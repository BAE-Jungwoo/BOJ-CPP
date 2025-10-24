#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T_case, n;
	long long dp[101] = { 0,1,1,1,2,2,3,4,5,7,9, };
	vector<long long> v;
	cin >> T_case;

	for (int j = 0; j < T_case; j++) {
		cin >> n;
		v.push_back(n);
	}

	for (int i = 11; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	for (const auto& num : v) {
		cout << dp[num] << '\n';
	}
	return 0;
}