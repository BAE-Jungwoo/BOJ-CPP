#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; // 숫자카드 개수
	cin >> n;

	vector<int> cards;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cards.push_back(x);
	}
	sort(cards.begin(), cards.end()); // 이분탐색을 위한 정렬

	int m; // 비교할 숫자 개수
	cin >> m;

	vector<int> nums; // 비교할 숫자 배열
	for (int i = 0; i < m; i++) {
		int y;
		cin >> y;
		nums.push_back(y);
	}

	for (int i = 0; i < m; i++) {
		int lower = lower_bound(cards.begin(), cards.end(), nums[i]) - cards.begin();
		int upper = upper_bound(cards.begin(), cards.end(), nums[i]) - cards.begin();
		cout << upper - lower << " ";
	}
	return 0;
}