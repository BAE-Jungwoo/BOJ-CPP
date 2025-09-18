#include <iostream>
using namespace std;

// 최대 공약수
int GCD(int a, int b) {
	if (b == 0) 
		return a;
	return GCD(b, a % b);
}

// 최소공배수
int LCM(int a, int b) {
	return (a * b) / GCD(a, b);
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	cout << GCD(n1, n2) << "\n" << LCM(n1, n2) << "\n";
	return 0;
}