#include <iostream>
using namespace std;

int main() {
	int input, num, arr[10001] = { 0, };
	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> num;
		arr[num]++;
	}

	for (int j = 1; j <= 10000; j++) {
		while (arr[j] > 0) {
			if (arr[j] > 0) {
				cout << j << "\n";
				arr[j]--;
			}
		}
	}
	return 0;
}