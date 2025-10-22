#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;
	while (N--) {
		int P;
		cin >> P;
		v.push_back(P);
	}
	sort(v.begin(), v.end());

	int cnt = 0;
	vector<int> sum;
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i];
		sum.push_back(cnt);
	}

	int result = 0;
	for (int j = 0; j < sum.size(); j++) {
		result += sum[j];
	}
	cout << result;
	return 0;
}