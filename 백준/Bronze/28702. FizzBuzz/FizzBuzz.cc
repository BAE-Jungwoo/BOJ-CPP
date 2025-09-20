#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	char arr[9];
	int check[4] = { 0, };

	for (int i = 0; i < 3; i++) {
		cin >> arr;
		if (isdigit(arr[0])) {
			check[i] = stoi(arr);
		}
	}
	
	for (int j = 0; j < 3; j++) {
		if (check[j] != 0) {
			if (j == 0) {
				if ((check[j] + 3) % 3 == 0 && (check[j] + 3) % 5 == 0) {
					cout << "FizzBuzz";
				}
				else if ((check[j] + 3) % 3 == 0 && (check[j] + 3) % 5 != 0) {
					cout << "Fizz";
				}
				else if ((check[j] + 3) % 3 != 0 && (check[j] + 3) % 5 == 0) {
					cout << "Buzz";
				}
				else {
					cout << check[j] + 3;
				}
				break;
			}
			else if (j == 1) {
				if ((check[j] + 2) % 3 == 0 && (check[j] + 2) % 5 == 0) {
					cout << "FizzBuzz";
				}
				else if ((check[j] + 2) % 3 == 0 && (check[j] + 2) % 5 != 0) {
					cout << "Fizz";
				}
				else if ((check[j] + 2) % 3 != 0 && (check[j] + 2) % 5 == 0) {
					cout << "Buzz";
				}
				else {
					cout << check[j] + 2;
				}
				break;
			}
			else if (j == 2) {
				if ((check[j] + 1) % 3 == 0 && (check[j] + 1) % 5 == 0) {
					cout << "FizzBuzz";
				}
				else if ((check[j] + 1) % 3 == 0 && (check[j] + 1) % 5 != 0) {
					cout << "Fizz";
				}
				else if ((check[j] + 1) % 3 != 0 && (check[j] + 1) % 5 == 0) {
					cout << "Buzz";
				}
				else {
					cout << check[j] + 1;
				}
				break;
			}
		}
	}
	return 0;
}