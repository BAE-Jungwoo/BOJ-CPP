#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K; // 가지고 있는 동전 종류, 가치의 합
	cin >> N >> K;

	vector<int> v;
	while (N--) {
		int coin;
		cin >> coin;
		v.push_back(coin);
	}

	int cnt = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (K / v[i] != 0) {
			cnt += K / v[i];
			K -= v[i] * (K / v[i]);
		}
	}
	cout << cnt;
	return 0;
}