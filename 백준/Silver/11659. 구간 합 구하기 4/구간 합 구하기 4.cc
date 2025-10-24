#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, num[100001], sum[100001] = { 0, }, n1, n2;
	num[0] = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		sum[i] = num[i] + sum[i - 1];
	}

	for(int j = 0; j < M; j++){
		cin >> n1 >> n2;
		cout << sum[n2] - sum[n1 - 1] << "\n";
	}
	return 0;
}