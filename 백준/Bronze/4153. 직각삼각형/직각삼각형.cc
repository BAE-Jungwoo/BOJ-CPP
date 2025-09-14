#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0; // 빗변, 세로, 가로 변

	while (1) {
		int sum = 0;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
			break;

		int Heru = max({ a,b,c });
		int Ausar = min({ a,b,c });
		int Auset = (a + b + c) - Heru - Ausar;

		sum = pow(Ausar, 2) + pow(Auset, 2);
		if (sum == pow(Heru, 2)) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}
	return 0;
}