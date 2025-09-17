#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer; // 결과로 반환할 선수들의 이름을 담은 배열

    map<string, int> map;
    for (int i = 0; i < players.size(); i++)
    {
        map[players[i]] = i; // 선수 이름과 해당 선수의 인덱스를 map에 저장
    }

    for (int i = 0; i < callings.size(); i++)
    {
        int idx = map[callings[i]];
        if (idx > 0) // 만약 추월한 선수가 있다면 
        {
            // 해당 선수와 그 앞의 선수를 swap
            swap(players[idx], players[idx - 1]);

            // 교환한 선수들의 인덱스 정보 업데이트
            map[callings[i]] = idx - 1;
            map[players[idx]] = idx;
        }
    }
    answer = players;

    return answer;
}
