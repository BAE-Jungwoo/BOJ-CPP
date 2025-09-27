#include <iostream>
using namespace std;

int dp_zero[40]; // 0이 출력되는 횟수를 저장할 배열
int dp_one[40]; // 1이 출력되는 횟수를 저장할 배열

int memo[40];
int fibonacci(int n) // 메모이제이션으로 n번 째 피보나치 수를 구하는 함수
{
	if (n <= 1)
	{
		memo[n] = n;
		return memo[n];
	}
	if (memo[n] != 0)
	{
		return memo[n];
	}
	else
	{
		memo[n]= fibonacci(n - 1) + fibonacci(n - 2);
		return memo[n];
	}
}

int main()
{
	int T;
	int n;
	cin >> T; // 테스트 케이스의 갯수

	dp_zero[0] = 1; // n = 0일 때, 0이 출력되는 횟수 1
	dp_one[0] = 0; // n = 0일 때, 1이 출력되는 횟수 0

	dp_zero[1] = 0; // n = 1일 때, 0이 출력되는 횟수 0
	dp_one[1] = 1; // n = 1일 때, 1이 출력되는 횟수 1

	for (int i = 0; i < T; i++)
	{
		cin >> n; // n번 째 피보나치 수 
		for (int j = 2; j <= n; j++)
		{
			dp_zero[j] = fibonacci(j - 1);
			dp_one[j] = fibonacci(j);
		}
		if (n == 0)
			cout << "1 0" << endl;
		else if (n == 1)
			cout << "0 1" << endl;
		else if (n > 1)
			cout << dp_zero[n] << " " << dp_one[n] << endl;
	}
	return 0;
}