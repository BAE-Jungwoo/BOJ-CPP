#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	// 벌집 둘레: 6, 12, 18, 24, 30, ...
	int layer = 0;
	if (n == 1) {
		layer++;
		cout << layer << endl;
		return 0;
	}

	int room_cnt = 1;
	while (room_cnt < n) {
		room_cnt += layer * 6;
		layer++;
	}
	cout << layer << endl;
}