#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
	int test;
	cin >> test;
	cin.ignore(); // 개행 문자 제거

	vector<string> result;
	bool isVps;

	for (int i = 0; i < test; i++) {
		string vps;
		getline(cin, vps);

		stack<char> s;
		isVps = true;

		for (int j = 0; j < vps.length(); j++) {
			if (vps[j] == '(') {
				s.push(vps[j]);
			}
			else if (vps[j] == ')') {
				if (s.empty() || s.top() != '(') {
					isVps = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) // 스택이 비어있는지 확인
			isVps = false;
		if (isVps)
			result.push_back("YES\n");
		else
			result.push_back("NO\n");
	}
	
	for (int m = 0; m < result.size(); m++) 
		cout << result[m];
	return 0;
}