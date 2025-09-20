#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;
    vector<int> part(n, 0);

    for (int i = 0; i < section.size(); i++) // 페인트를 칠해야 되는 구역 찾기
    {
        part[section[i] - 1] = 1; // 구역을 찾으면 값 변환
    }

    for (int i = 0; i < n; i++)
    {
        if (part[i]) // 페인트를 칠해야 되는 구역을 찾으면
        {
            answer++;
            for (int j = i; j < min(i + m, n); j++) // 페인트를 칠할 구역
            {
                part[j] = 0;
            }
        }
    }

    return answer;
}