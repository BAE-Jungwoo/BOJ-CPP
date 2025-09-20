#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;

    for (int j = 0; j < targets.size(); j++)
    {
        int cnt = 0;
        for (int u = 0; u < targets[j].length(); u++)
        {
            int midx = INT_MAX;
            for (int i = 0; i < keymap.size(); i++)
            {
                int p = keymap[i].find(targets[j][u]);
                if (p != string::npos) // 일치하는 값이 있으면
                {
                    midx = min(midx, p); // 순회하며 최소 인덱스 추적
                }
            }
            if (midx != INT_MAX)
            {
                cnt += (midx + 1); // 최솟값에 1을 더하여 횟수 누적
            }
            else
            {
                cnt = -1;
                break;
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}