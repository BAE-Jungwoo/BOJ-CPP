#include <iostream>
using namespace std;

int main() {
	int number;
	cin >> number;

	for (int i = 1; i < number; i++) {
		int sum = i; // 분해합은 자기부터
		int digit = i;
		while (digit) {
			sum += digit % 10; // 일의 자리 수 더하기
			digit /= 10;
		}
		if (sum == number) { // 생성자 일 때
			cout << i; 
			return 0;
		}
	}
	cout << 0;
}