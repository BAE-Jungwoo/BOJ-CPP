#include <iostream>

using namespace std;

int dp[1000001];

int main()
{
	int x;
	cin >> x; // 1 <= x <= 10^6

	dp[0] = dp[1] = 0;
	dp[2] = dp[3] = 1;

	for (int i = 4; i <= x; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) // 2로 나눠지면
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		if (i % 3 == 0) // 3으로 나눠지면
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	cout << dp[x] << endl;

	return 0;
}