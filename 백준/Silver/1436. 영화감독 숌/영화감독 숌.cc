#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N; 

	int num = 666;
	int cnt = 0;
	string target;
	while (1) {
		target = to_string(num);
		for (int j = 0; j < target.length() - 2; j++) {
			if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6') {
				cnt++;
				if (cnt == N)
				{
					cout << num;
					return 0;
				}
				break;
			}
		}
		num++;
	}
}