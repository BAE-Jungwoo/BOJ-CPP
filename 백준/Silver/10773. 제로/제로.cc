#include <iostream>
#include <stack>
using namespace std;

int main() {
	int k;
	long long cnt = 0;
	stack<int> s;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num != 0) {
			s.push(num);
			cnt += num;
		}
		else if (num == 0 && s.empty() == 0) {
			cnt -= s.top();
			s.pop();
		}
	}
	cout << cnt;
	return 0;
}