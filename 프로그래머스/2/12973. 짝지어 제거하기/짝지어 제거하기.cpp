#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stack;

    stack.push(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (stack.empty())
        {
            stack.push(s[i]);
            continue;
        }

        char str = stack.top();
        if (str == s[i])
            stack.pop();
        else
            stack.push(s[i]);
    }

    answer = stack.empty() ? 1 : 0;
    return answer;
}