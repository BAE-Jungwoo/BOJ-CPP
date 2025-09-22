#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    // 파기해야 할 개인정보의 번호를 오름차순으로 담은 배열
    vector<int> answer;
    int cnt = 0;

    string temp_today;
    string temp_terms;
    string temp_privacies;
    string temp_mod;

    // 자른 요소들이 저장되어 있는 문자열 배열
    vector<int> v_today;
    vector<string> v_terms;
    vector<string> v_privacies;

    istringstream s_today(today);
    while (getline(s_today, temp_today, '.')) // today의 요소를 '.'를 기준으로 자르기
    {
        v_today.push_back(stoi(temp_today)); // 자른 요소를 v에 저장
    }

    for (int i = 0; i < terms.size(); i++)
    {
        istringstream s_terms(terms[i]);
        while (getline(s_terms, temp_terms, ' ')) // terms의 요소를 ' '를 기준으로 자르기
        {
            v_terms.push_back(temp_terms); // 자른 요소를 v에 저장
        }
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        istringstream s_privacies(privacies[i]);
        while (getline(s_privacies, temp_privacies, ' ')) // privacies의 요소를 ' '를 기준으로 자르기
        {
            v_privacies.push_back(temp_privacies); // 자른 요소를 v에 저장
        }
    }

    vector<int> v_mod_day;
    for (int i = 0; i < (v_privacies.size() / 2); i++)
    {
        istringstream s_mod_day(v_privacies[2 * i]);
        while (getline(s_mod_day, temp_mod, '.'))
        {
            v_mod_day.push_back(stoi(temp_mod));
        }
    }

    for (int j = 0; j < (v_privacies.size() / 2); j++)
    {
        for (int i = 0; i < (v_terms.size() / 2); i++)
        {
            if (v_privacies[2 * j + 1] == v_terms[2 * i])
            {
                if (v_mod_day[3 * j + 1] + stoi(v_terms[2 * i + 1]) > 12)
                {
                    v_mod_day[3 * j] += (v_mod_day[3 * j + 1] + stoi(v_terms[2 * i + 1])) / 12;
                    v_mod_day[3 * j + 1] = (v_mod_day[3 * j + 1] + stoi(v_terms[2 * i + 1])) % 12;
                    if (v_mod_day[3 * j + 1] == 0)
                    {
                        v_mod_day[3 * j] -= 1;
                        v_mod_day[3 * j + 1] = 12;
                    }
                }
                else
                {
                    v_mod_day[3 * j + 1] += stoi(v_terms[2 * i + 1]);
                }
            }
        }
    }

    // v_today랑 v_mod_day랑 날짜 비교 후 파기해야 될 정보가 있으면 cnt++
    for (int i = 0; i < (v_mod_day.size() / 3); i++) // i < 4
    {
        cnt++;
        if (v_mod_day[3 * i] == v_today[0]) // 년도가 같을 때
        {
            if (v_mod_day[3 * i + 1] < v_today[1]) // 달이 작을 때
            {
                answer.push_back(cnt);
                continue;
            }
            else if (v_mod_day[3 * i + 1] == v_today[1]) // 년도와 달이 같을 때
            {
                if (v_mod_day[3 * i + 2] > v_today[2]) // 일이 클 때
                {
                    continue;
                }
                else if (v_mod_day[3 * i + 2] <= v_today[2]) // 일이 같거나 작을 때
                {
                    answer.push_back(cnt);
                    continue;
                }
            }
            else if (v_mod_day[3 * i + 1] > v_today[1]) // 달이 클 때
            {
                continue;
            }
        }
        else if (v_mod_day[3 * i] < v_today[0]) // 년도가 작을 때 파기
        {
            answer.push_back(cnt);
            continue;
        }
        else if (v_mod_day[3 * i] > v_today[0]) // 년도가 클 때 보관
        {
            continue;
        }
    }

    return answer;
}