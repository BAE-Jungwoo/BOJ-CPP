#include <iostream>
using namespace std;

int main() {
	int T, floor, room;
	cin >> T;

	for (int i = 0; i < T; i++) { // Test cases
		int sum = 0;
		cin >> floor;
		cin >> room;

		int fam[15][15] = { 0, };

		for(int i = 0; i < 15; i++){
			fam[0][i] = i + 1;
			fam[i][0] = 1;
		}

		for (int k = 0; k < floor; k++) { 
			for (int m = 0; m < room; m++) { 
				if (floor == 1) { // 1층일 때
					sum += fam[0][m];
				}
				if (k == 0) {
					continue;
				}
				else if (k != 0) {
					if (m == 0) {
						fam[k][m] = fam[k - 1][m];
						sum = fam[k][m];
					}
					else {
						fam[k][m] = fam[k][m - 1] + fam[k - 1][m];
						sum += fam[k][m];
					}
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
}