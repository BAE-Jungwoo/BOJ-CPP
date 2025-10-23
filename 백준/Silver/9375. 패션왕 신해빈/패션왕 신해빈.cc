#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase, n;
	cin >> testcase;

	string name, type;
	for (int i = 0; i < testcase; i++) {
		unordered_map<string, int> clothes;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> name >> type;
			clothes[type]++;
		}

		int result = 1;
		for (auto it = clothes.begin(); it != clothes.end(); it++) {
			result *= (it->second + 1);
		}
		cout << result - 1 << "\n";
	}
}