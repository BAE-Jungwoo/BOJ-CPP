#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	bool S[21] = { false, };
	cin >> m;

	while (m--) {
		string cmd;
		int x;
		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			S[x] = true;
		}
		else if (cmd == "remove") {
			cin >> x;
			S[x] = false;
		}
		else if (cmd == "check") {
			cin >> x;
			cout << S[x] << "\n";
		}
		else if (cmd == "toggle") {
			cin >> x;
			if(S[x])
				S[x] = false;
			else
				S[x] = true;
		}
		else if (cmd == "all") {
			fill(S, S + 21, true);
		}
		else if (cmd == "empty") {
			fill(S, S + 21, false);
		}
	}
	return 0;
}