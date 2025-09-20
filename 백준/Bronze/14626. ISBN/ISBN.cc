#include <iostream>
using namespace std;

int main() {
	char arr[14];
	int weight, m, check = 0, sum = 0;
	cin >> arr;

	for (int i = 0; i < 13; i++) {
		if (arr[i] == '*') {
			check = i; // 훼손된 위치 저장
			if (check % 2 == 1) 
				weight = 3;
			else 
				weight = 1;
			continue;
		}
		else if (i % 2 == 1) {
			sum += 3 * (arr[i] - '0');
			arr[i] *= 3;
			continue;
		}
		sum += arr[i] - '0';
	}
	
	for (m = 0; m < 10; m++) {
		if ((sum + weight * m) % 10 == 0) {
			cout << m << endl;
			return 0;
		}
	}
}