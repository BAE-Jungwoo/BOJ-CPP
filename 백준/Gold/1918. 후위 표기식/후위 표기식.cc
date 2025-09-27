#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getOpPriority(char op)
{
    switch (op)
    {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

// 중위표기식을 후위표기식으로 변환하는 함수
string infixToPostfix(string s)
{
    stack<char> stack;
    string postfixExpression = "";  // 후위표기식 결과를 저장하는 변수

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') // 연산자
        {
            if (stack.empty()) // 스택이 비어있으면 값을 push
            {
                stack.push(s[i]);
            }
            else // 스택이 비어있지 않으면
            {
                // 현재 연산자 우선순위보다 stack의 top 연산자 우선순위가 높을때 까지 pop 후 
                // 코드 작성
                while (!stack.empty() && getOpPriority(s[i]) <= getOpPriority(stack.top()))
                {
                    postfixExpression += stack.top();
                    stack.pop();
                }
                stack.push(s[i]); // 현재 연산자 push
            }
        }
        else if (s[i] == '(') // 왼쪽괄호
        {
            stack.push(s[i]);
        }
        else if (s[i] == ')') // 오른쪽괄호
        {
            // 왼쪽괄호 위에 쌓여있는 모든 연산자 pop 후 왼쪽괄호 삭제
            // 코드 작성
            while (stack.top() != '(')
            {
                postfixExpression += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else // 피연산자
        {
            // 코드 작성
            postfixExpression += s[i];
        }
    }
    // 스택의 남은 연산자를 모두 pop
    while (!stack.empty())
    {
        // 코드 작성
        postfixExpression += stack.top();
        stack.pop();
    }
    return postfixExpression;
}

int main()
{
    string s = "";
    cin >> s;
    string answer = infixToPostfix(s);
    cout << answer;
    return 0;
}