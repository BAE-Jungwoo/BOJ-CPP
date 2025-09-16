#include <iostream>
#include <queue>

using namespace std;

int main() 
{
	int N = 0; // N장의 카드
	queue<int> q; // 큐 선언

	cin >> N; // 입력 받기

	for (int i = 1; i <= N; i++) // 카드를 순서대로 큐에 넣기
	{
		q.push(i);
	}

	while (q.size() > 1) // 큐의 사이즈가 1이 되는 순간 끝
	{
		q.pop();
		int top_val = q.front(); // 가장 위의 카드는 버리면 안되기 때문에 top_val에 담아둔
		q.pop(); 
		q.push(top_val); // 가장 위의 카드 다시 넣어줌
	}

	cout << q.front();
	return 0;
}