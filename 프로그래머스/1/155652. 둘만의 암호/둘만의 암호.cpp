#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Existskip(char current, string skip) // 스킵할 문자가 존재하는지 확인하는 함수
{
    for (int i = 0; i < skip.length(); i++)
    {
        if (current == skip[i]) // 스킵할 문자가 존재하면
            return true;
    }
    return false; // 스킵할 문자가 존재하지 않으면 거짓 반환
}

string solution(string s, string skip, int index)
{
    string answer = "";
    for (int i = 0; i < s.length(); i++)
    {
        char currentChar = s[i];
        for (int j = 0; j < index;)
        {
            currentChar++;
            if (currentChar > 'z') // 'z'를 넘어가면 
            {
                currentChar = 'a'; // 'a'로 돌아감
            }

            if (Existskip(currentChar, skip) == false) // skip에 포함되지 않는 문자이면 
            {
                j++;
            }
            else if (Existskip(currentChar, skip) == true) // skip에 포함된 문자이면 
            {
                continue;
            }
        }
        answer += currentChar;
    }
    return answer;
}