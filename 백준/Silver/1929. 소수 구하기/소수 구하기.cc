#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	vector<int> prime_numbers;
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		if (i == 1) continue;
		if (i == 2) {
			prime_numbers.push_back(i);
			continue;
		}
		if (i % 2 == 0) continue;
		else {
			bool isPrime = true;
			for (int j = 3; j <= i; j += 2) {
				if (j * j > i) break;
				if (i % j == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) prime_numbers.push_back(i);
		}
	}

	for (int num = 0; num < prime_numbers.size(); num++) {
		cout << prime_numbers[num] << "\n";
	}
	return 0;
}