#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    string answer = "";
    unordered_map<char, int> map;
    map['R'] = 0, map['T'] = 0, map['C'] = 0, map['F'] = 0, map['J'] = 0,
    map['M'] = 0, map['A'] = 0, map['N'] = 0;

    for (int i = 0; i < survey.size(); i++)
    {
        if (choices[i] < 4) // 매우 비동의 ~ 약간 비동의
        {
            map[survey[i][0]] += (4 - choices[i]);
        }
        else if (choices[i] > 4) // 약간 동의 ~ 매우 동의
        {
            map[survey[i][1]] += (choices[i] - 4);
        }
    }

    if (map['R'] > map['T'])
        answer += 'R';
    else if (map['R'] < map['T'])
        answer += 'T';
    else
        answer += 'R';

    if (map['C'] > map['F'])
        answer += 'C';
    else if (map['C'] < map['F'])
        answer += 'F';
    else
        answer += 'C';

    if (map['J'] > map['M'])
        answer += 'J';
    else if (map['J'] < map['M'])
        answer += 'M';
    else
        answer += 'J';

    if (map['A'] > map['N'])
        answer += 'A';
    else if (map['A'] < map['N'])
        answer += 'N';
    else
        answer += 'A';

    return answer;
}