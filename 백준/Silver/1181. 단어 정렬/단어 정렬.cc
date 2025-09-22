#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) { // 길이가 같으면
		return a < b; // 사전 순으로 정렬
	}
	return a.length() < b.length(); // 길이 순으로 정렬
}

int main() {
	int n;
	cin >> n;
	string arr[20001];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	/* 시간 복잡도가 O(n^2) → 시간초과
	for (int j = 0; j < n; j++) {
		for (int k = j + 1; k < n; k++) {
			if (arr[j].compare(arr[k]) == 0) {
				arr[k].erase();
			}

			if (arr[j].length() > arr[k].length()) {
				swap(arr[j], arr[k]);
			}
			else if (arr[j].length() == arr[k].length()) {
				if (arr[j] > arr[k]) {
					swap(arr[j], arr[k]);
				}
			}
		}
	}
	*/

	// 시간 복잡도가 O(n log n)
	sort(arr, arr + n, compare);

	for (int m = 0; m < n; m++) {
		if (m == 0 || arr[m] != arr[m - 1])  // 바로 앞과 다를 때만 출력
			cout << arr[m] << '\n';
	}
	return 0;
}