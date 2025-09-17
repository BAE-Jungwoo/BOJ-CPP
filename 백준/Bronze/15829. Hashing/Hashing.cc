#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int r = 31, sum = 0;

	int L; // 문자열 길이
	cin >> L;
	string S; // 문자열
	cin >> S;

	for (int i = 0; i < L; i++) {
		S[i] = S[i] - 'a' + 1; // a를 1으로 맞춤
		sum += S[i] * pow(r, i); // 해시 함수
	}
	cout << sum << endl;
	return 0;
}