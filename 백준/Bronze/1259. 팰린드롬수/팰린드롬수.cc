#include <iostream>
#include <string>
using namespace std;

int main() {
	string number;

	while (1) {
		cin >> number;
		if (stoi(number) == 0) 
			break;

		bool is_palindrome = true;
		for (int i = 0; i < number.length() / 2; i++) {
			if (number[i] != number[number.length() - 1 - i]) {
				is_palindrome = false;
				break;
			}
		}
		if (is_palindrome)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}