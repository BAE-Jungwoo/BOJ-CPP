#include <iostream>
using namespace std;

int dp[5001];

int main()
{
	int N;
	dp[0] = dp[1] = dp[2] = dp[4] = -1; // 3kg과 5kg으로 만들지 못하는 봉지 수는 -1
	dp[3] = dp[5] = 1; // 3kg과 5kg를 만드는 가장 최소의 봉지수는 1

	cin >> N;

	// 3과 5 다음인 6부터 for loop 순회
	for (int i = 6; i <= N; i++)
	{
		if (dp[i - 3] == -1 && dp[i - 5] == -1) // N kg을 만들 수 없는 경우
		{
			dp[i] = -1;
		}
		else if (dp[i - 3] != -1 && dp[i - 5] == -1) // N kg이 3kg으로만 만들 수 있는 경우
		{
			dp[i] = dp[i - 3] + 1;
		}
		else if (dp[i - 3] == -1 && dp[i - 5] != -1) // N kg이 5kg으로만 만들 수 있는 경우
		{
			dp[i] = dp[i - 5] + 1;
		}
		else // N kg이 3kg과 5kg으로 만들 수 있는 경우
		{
			dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
		}
	}
    cout << dp[N] << endl;
    return 0;
}