#include <iostream>
#include <string>
using namespace std;

int main() {
	int r = 31, L;
	long long sum = 0, M = 1234567891, power = 1; // 해시 값
	cin >> L;

	string S; // 문자열
	cin >> S;

	for (int i = 0; i < L; i++) {
		int val = S[i] - 'a' + 1; // a를 1으로 맞춤
		sum += (val * (power % M)) % M; // 해시 함수
		power = (power * r) % M; // r의 i제곱
	}
	sum %= M; 

	cout << sum << endl;
	return 0;
}