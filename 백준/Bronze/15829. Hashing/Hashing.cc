#include <iostream>
#include <string>
using namespace std;

int main() {
	int r = 31, L;
	long long sum = 0, M = 1234567891, power = 1;
	cin >> L;

	string S; 
	cin >> S;

	for (int i = 0; i < L; i++) {
		int val = S[i] - 'a' + 1; // a를 1으로 맞춤
		sum += (val * power) % M; // 해시 함수
		power = (power * r) % M; // r의 i제곱
	}
	sum %= M; 

	cout << sum << endl;
	return 0;

}

