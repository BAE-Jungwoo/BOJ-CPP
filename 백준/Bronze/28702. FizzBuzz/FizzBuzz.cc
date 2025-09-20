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
			int num = check[j] + (3 - j);
			if(num % 15 == 0) cout << "FizzBuzz" << endl;
			else if(num % 3 == 0) cout << "Fizz" << endl;
			else if(num % 5 == 0) cout << "Buzz" << endl;
			else cout << num << endl;
			break;
		}
	}
	return 0;
}