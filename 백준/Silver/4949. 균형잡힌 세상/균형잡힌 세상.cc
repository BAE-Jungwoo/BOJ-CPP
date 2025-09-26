#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
bool balance;

int main() {
	vector<string> v;

    while (1) {
        string str;
		getline(cin, str);
		if (str == ".") // 입력 종료 조건
            break;

        stack<char> s;
        balance = true;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '.') break;
            if(str == " .") break;

            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            }
            else if (str[i] == ')') {
                if (s.empty() || s.top() != '(') {
                    balance = false;
                    break;
                }
                s.pop();
            }
            else if (str[i] == ']') {
                if (s.empty() || s.top() != '[') {
                    balance = false;
                    break;
                }
                s.pop();
            }
        }
		if (!s.empty()) 
            balance = false;

        if (balance) 
			v.push_back("yes\n");
        else 
			v.push_back("no\n");
    }

    for(int i=0; i < v.size(); i++)
		cout << v[i];
    return 0;
}