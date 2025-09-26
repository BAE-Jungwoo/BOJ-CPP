#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ans;
    int size = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 48 && s[i] <= 57) { // s의 원소가 숫자일 때
            ans.push_back(s[i]);
        }
        else { // s의 원소가 영문일 때
            if (s[i] == 'z') {          // 0
                ans.push_back('0');
                i = i + 3;
            }
            else if (s[i] == 'o') {     // 1
                ans.push_back('1');
                i = i + 2;
            }
            else if (s[i] == 't') {     // 2, 3
                if (s[i + 1] == 'w') {
                    ans.push_back('2');
                    i = i + 2;
                }   
                else {
                    ans.push_back('3');
                    i = i + 4;
                }
            }
            else if (s[i] == 'f') {     // 4, 5
                if (s[i + 1] == 'o') {
                    ans.push_back('4');
                    i = i + 3;
                }
                else {
                    ans.push_back('5');
                    i = i + 3;
                }           
            }
            else if (s[i] == 's') {     // 6, 7
                if (s[i + 1] == 'i') {
                    ans.push_back('6');
                    i = i + 2;
                }
                else {
                    ans.push_back('7');
                    i = i + 4;
                }
            }
            else if (s[i] == 'e') {     // 8
                ans.push_back('8');
                i = i + 4;
            }
            else if (s[i] == 'n') {     // 9
                ans.push_back('9');
                i = i + 3;
            }
        }
    }

    answer = stoi(ans);
    return answer;
}