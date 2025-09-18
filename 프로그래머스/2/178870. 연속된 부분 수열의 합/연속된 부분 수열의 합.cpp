#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;

    int start = 0, end = 0; // 부분 수열의 시작 인덱스 & 마지막 인덱스
    int sum = sequence[start];
    int minLength = sequence.size(); // 부분 수열의 최소 길이
    int minStart = 0, minEnd = 0; // 부분 수열의 최소 길이의 시작 인덱스 & 마지막 인덱스

    while (start <= end && end < sequence.size())
    {
        if (sum < k) // 부분 수열의 합이 더 커져야 될 때
        {
            end++; // end 포인터 이동
            if (end < sequence.size())
            {
                sum += sequence[end];
            }
        }
        else if (sum > k) // 부분 수열의 합이 더 작아져야 될 때
        {
            sum -= sequence[start];
            start++; // start 포인터 이동
        }
        else if (sum == k) // 부분 수열의 합이 일치할 때
        {
            if (end - start < minLength) // 기존 최소 길이보다 작을 때
            {
                minLength = end - start; // 최소 길이 업데이트
                minStart = start; // 시작 인덱스 업데이트
                minEnd = end; // 마지막 인덱스 업데이트
            }
            end++; // end 포인터 이동

            if (end < sequence.size())
            {
                sum += sequence[end];
            }
        }
    }
    answer.push_back(minStart);
    answer.push_back(minEnd);

    return answer;
}