#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

string solution(string X, string Y)
{
    string answer = "";
    int idx;
    int Xidx;
    int Yidx;
    vector<char> Xpartner;
    vector<char> Ypartner;

    for (int i = 0; i < Y.length(); i++) // Y를 순회하면서 X에 같은 값이 있는 지 확인
    {
        Xidx = X.find(Y[i]); // 짝꿍인 인덱스 찾기
        if (Xidx != string::npos) // 일치하는 값이 있으면
        {
            Xpartner.emplace_back(X[Xidx]); // 벡터에 값 넣기
        }
    }

    for (int i = 0; i < X.length(); i++) // X를 순회하면서 Y에 같은 값이 있는 지 확인
    {
        Yidx = Y.find(X[i]); // 짝꿍인 인덱스 찾기
        if (Yidx != string::npos) // 일치하는 값이 있으면
        {
            Ypartner.emplace_back(Y[Yidx]); // 벡터에 값 넣기
        }
    }

    unordered_map<char, int> map;
    for (char c : Xpartner)
    {
        map[c]++;
    }

    vector<char> pairs;
    for (char c : Ypartner)
    {
        if (map.find(c) != map.end() && map[c] > 0)
        {
            pairs.push_back(c);
            map[c]--;
        }
    }

    if (pairs.empty()) // 벡터가 비어 있으면
    {
        answer = "-1";
        return answer;
    }
    else // 벡터에 값이 있으면
    {
        bool Allzero = true;
        for (int i = 0; i < pairs.size(); i++)
        {
            if (pairs[i] != '0') // 0이 아닌 요소를 찾았으면
            {
                Allzero = false;
            }
        }

        if (Allzero == true) // 벡터에 값이 0만 있으면
        {
            answer = '0';
            return answer;
        }
        else
        {
            sort(pairs.begin(), pairs.end(), greater<>()); // 내림차순으로 정렬

            for (int i = 0; i < pairs.size(); i++)
            {
                answer += pairs[i];
            }
            return answer;
        }
    }
}