#include <iostream>
using namespace std;

int main() {
	int a, b, v, day = 0;
	cin >> a >> b >> v;

	/* 시간 초과
	while (v > 0) {
		if (a >= v) {
			day++;
			break;
		}
		else if (a < v) {
			v -= (a - b);
			day++;
		}
	}
	*/

	day = (v - a) / (a - b);
	if ((v - a) % (a - b) == 0) 
		day++;
	else
		day += 2;

	cout << day;
	return 0;
}