#include <iostream>
using namespace std;

int main() {
	int num, minor, count = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> minor;

		if (minor == 1) continue;
		else if (minor == 2) count++;
		else {
			int check = 0;
			for (int j = 1; j <= minor; j++) {
				if (minor % 2 == 0) break;
				else {
					if (minor % j == 0) {
						check++;
					}
				}
			}
			if (check == 2) count++;
		}
	}
	cout << count << "\n";
	return 0;
}