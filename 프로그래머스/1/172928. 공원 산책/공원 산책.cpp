#include <iostream>
#include <string>
#include <vector>
#include <cstdbool>
using namespace std;

// 동쪽으로 이동할 때의 장애물이 있는지 확인하는 함수
bool obstacleDetected_EColumn(int i, vector<string>& park, vector<string>& routes, int row, int column)
{
    for (int t = column - (routes[i][2] - 48); t <= column; t++)
    {
        if (column >= 0 && column < park[0].length())
        {
            if (park[row][t] == 'X')
            {
                return true;
            }
        }
    }
    return false;
}

// 서쪽으로 이동할 때의 장애물이 있는지 확인하는 함수
bool obstacleDetected_WColumn(int i, vector<string>& park, vector<string>& routes, int row, int column)
{
    for (int t = column + (routes[i][2] - 48); t >= column; t--)
    {
        if (column >= 0 && column < park[0].length())
        {
            if (park[row][t] == 'X')
            {
                return true;
            }
        }
    }
    return false;
}

// 남쪽으로 이동할 때의 장애물이 있는지 확인하는 함수
bool obstacleDetected_SRow(int i, vector<string>& park, vector<string>& routes, int row, int column)
{
    for (int t = row - (routes[i][2] - 48); t <= row; t++)
    {
        if (row >= 0 && row < park.size())
        {
            if (park[t][column] == 'X')
            {
                return true;
            }
        }
    }
    return false;
}

// 북쪽으로 이동할 때의 장애물이 있는지 확인하는 함수
bool obstacleDetected_NRow(int i, vector<string>& park, vector<string>& routes, int row, int column)
{
    for (int t = row + (routes[i][2] - 48); t >= row; t--)
    {
        if (row >= 0 && row < park.size())
        {
            if (park[t][column] == 'X')
            {
                return true;
            }
        }
    }
    return false;
}

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;
    int row = park.size(); // 행의 크기, 4
    int column = park[0].length(); // 열의 크기, 3
    int start_row, start_column;

    for (int i = 0; i < row; i++) // 행
    {
        for (int j = 0; j < park[i].size(); j++) // 열
        {
            if (park[i][j] == 'S') // 시작 지점의 인덱스 값 찾기
            {
                start_row = i; // 시작 지점의 행의 요소 값, 0
                start_column = j; // 시작 지점의 열의 요소 값, 1
            }
        }
    }

    for (int i = 0; i < routes.size(); i++)
    {
        if (routes[i][0] == 'E') // 동쪽으로
        {
            start_column += (routes[i][2] - 48);
            if (start_column > column - 1 || obstacleDetected_EColumn(i, park, routes, start_row, start_column)) // 공원을 벗어나거나 장애물을 만나면
            {
                start_column -= (routes[i][2] - 48);
            }
        }
        else if (routes[i][0] == 'W') // 서쪽으로
        {
            start_column -= (routes[i][2] - 48);
            if (start_column < 0 || obstacleDetected_WColumn(i, park, routes, start_row, start_column)) // 공원을 벗어나거나 장애물을 만나면
            {
                start_column += (routes[i][2] - 48);
            }
        }
        else if (routes[i][0] == 'N') // 북쪽으로
        {
            start_row -= (routes[i][2] - 48);
            if (start_row < 0 || obstacleDetected_NRow(i, park, routes, start_row, start_column)) // 공원을 벗어나거나 장애물을 만나면
            {
                start_row += (routes[i][2] - 48);
            }
        }
        else if (routes[i][0] == 'S') // 남쪽으로
        {
            start_row += (routes[i][2] - 48);
            if (start_row > row - 1 || obstacleDetected_SRow(i, park, routes, start_row, start_column)) // 공원을 벗어나거나 장애물을 만나면
            {
                start_row -= (routes[i][2] - 48);
            }
        }
    }
    answer.push_back(start_row);
    answer.push_back(start_column);

    return answer;
}