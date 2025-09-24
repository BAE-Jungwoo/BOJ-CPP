#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Binary_search(vector<int>& v, int target) {
	int low = 0;
	int high = v.size() - 1;
	
	while (low <= high) {
		int mid = (low + high) / 2;

		if (v[mid] == target) {
			cout << 1 << "\n";
			return;
		}
		else if (v[mid] > target) {
			high = mid - 1;
		}
		else if(v[mid] < target) {
			low = mid + 1;
		}
	}
	cout << 0 << "\n";
	return;
}

int main() {
	int N, M;

	vector<int> v, finder;

	cin >> N; // 전체 수
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	cin >> M; // 찾을 수의 개수
	for(int j = 0; j < M; j++) {
		int y;
		cin >> y;
		finder.push_back(y);
	}

	for(int k = 0; k < M; k++) {
		Binary_search(v, finder[k]);
	}
	return 0;
}