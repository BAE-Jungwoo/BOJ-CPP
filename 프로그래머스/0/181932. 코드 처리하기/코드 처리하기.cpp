#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string code)
{
    bool mode = false; // false = 0, mode는 0부터 시작
    string answer = ""; // ret

    for (int i = 0; i < code.length(); i++)
    {
        if (mode == false)
        {
            if (code[i] != '1' && (i % 2 == 0))
            {
                answer.push_back(code[i]);
            }
            else if (code[i] == '1')
            {
                mode = true;
            }
        }
        else if (mode == true)
        {
            if (code[i] != '1' && (i % 2 != 0))
            {
                answer.push_back(code[i]);
            }
            else if (code[i] == '1')
            {
                mode = false;
            }
        }
    }

    if (answer.empty())
        return "EMPTY";
    else
        return answer;
}