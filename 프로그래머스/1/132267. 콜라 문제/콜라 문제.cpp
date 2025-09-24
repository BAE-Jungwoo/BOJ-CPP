#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    int cnt = 0;
    int answer = 0;

    while (1) 
    {
        cnt = (n / a) * b; // 받은 콜라의 갯수
        answer += cnt; // 받은 콜라의 갯수 업데이트
        n = (n % a) + cnt; // 빈 병의 갯수
        if (n < a) // 보유중인 빈 병이 더 적다면
        {
            return answer;
        }
    }
}