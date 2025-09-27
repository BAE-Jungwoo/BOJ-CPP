#include <iostream>
using namespace std;

// 1 : 1개
// 2 : 2개
// 3 : 4개
// 4 : 7개
// 5 : 13개
// 6 : 24개
// 7 : 44개
// ... 10 : 274개
// n = 4부터 시작하는 점화식 : dp[n] = dp[n-1] + dp[n-2] + dp[n-3]

int dp[11];

int main()
{
	int T; // 입력할 테스트 케이스의 갯수
	cin >> T;

	int n;
	dp[0] = 1; // n = 1일 때
	dp[1] = 2; // n = 2일 때
	dp[2] = 4; // n = 3일 때

	for (int i = 0; i < T; i++)
	{
		cin >> n; // 정수 n을 입력
		for (int j = 3; j < n; j++)
		{
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[n - 1] << endl;
	}
	return 0;
}