#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int arr[8001];

int main() {
	int N, num; 
	cin >> N;

	vector<int> v;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
		sum += num;
		if (num < 0) {
			arr[abs(num) + 4000]++;
		}
		else {
			arr[num]++;
		}
	}
	sort(v.begin(), v.end());
	int avg = round((double)sum / N); // 산술평균
	int mid = v[N / 2]; // 중앙값
	int range = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()); // 범위
	
	vector <pair<int, int>> f;
	int freq = 0; // 최빈값

	if (N == 1) {
		freq = v[0];
	}
	else {
		for (int i = 0; i < 8001; i++) {
			if (arr[i] > freq) {
				freq = arr[i];
				f.clear();
				if (i > 4000) {
					f.push_back({ -(i - 4000), arr[i] });
				}
				else {
					f.push_back({ i, arr[i] });
				}
			}
			else if (arr[i] == freq && arr[i] != 0) {
				if (i > 4000) {
					f.push_back({ -(i - 4000), arr[i] });
				}
				else {
					f.push_back({ i, arr[i] });
				}
			}
		}

		if (f.size() >= 2) {
			sort(f.begin(), f.end());
			freq = f[1].first;
		}
		else {
			freq = f[0].first;
		}
	}

	cout << avg << "\n" << mid << "\n" << freq << "\n" << range;
	return 0;
}