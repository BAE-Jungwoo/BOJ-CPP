#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;
    vector<int> idx;

    for (int i = 0; i < ingredient.size(); i++)
    {
        idx.push_back(ingredient[i]);

        if (idx.size() >= 4
            && idx[idx.size() - 4] == 1
            && idx[idx.size() - 3] == 2
            && idx[idx.size() - 2] == 3
            && idx[idx.size() - 1] == 1
            )
        {
            answer++;
            idx.pop_back(); // 1
            idx.pop_back(); // 3 
            idx.pop_back(); // 2
            idx.pop_back(); // 1
        }
    }
    return answer;
}