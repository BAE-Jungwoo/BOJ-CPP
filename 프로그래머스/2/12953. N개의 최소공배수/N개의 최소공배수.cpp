#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) // 최대공약수
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    int num;
    while (b != 0)
    {
        num = a % b;
        a = b;
        b = num;
    }
    return a;
}

int LCM(int a, int b) // 최소공배수 : 두 수의 곱 / 최대공약수
{
    int lcm = 0;
    lcm = a * b / GCD(a, b);
    return lcm;
}

int solution(vector<int> arr) 
{
    int answer = arr[0];
    for (int i = 0; i < arr.size() - 1; i++)
    {
        answer = LCM(answer, arr[i + 1]);
    }
    return answer;
}   