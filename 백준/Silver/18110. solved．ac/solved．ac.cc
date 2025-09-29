#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	if (n == 0) {
		cout << "0\n";
		return 0;
	}

	vector<int> res;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		res.push_back(a);
	}
	sort(res.begin(), res.end());

	int avg = (int)round(n * 0.15); // 절삭 개수
	long double sum = 0;

	// pop_back → O(1), erase → O(n)
	for (int j = avg; j < n - avg; j++) {
		sum += res[j];
	}
	cout << (int)round((double)sum / (res.size() - 2 * avg)) << "\n";
	return 0;
}