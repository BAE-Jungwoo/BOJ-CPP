#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 1 || n == 0) 
		return 1;
	return n * factorial(n - 1);
}

int main() {
	int num, k;
	cin >> num >> k;
	// nCr, 5C2 = 5! / (2! * 3!)
	
	cout << factorial(num) / (factorial(k) * factorial(num - k));
	return 0;
}