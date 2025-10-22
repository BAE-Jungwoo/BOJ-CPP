#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; // 듣도 못한 수, 보도 못한 수
	cin >> N >> M;
	set<string> s;
	vector<string> v;

	while (N--) {
		string name1;
		cin >> name1;
		s.insert(name1);
	}
	
	while (M--) {
		string name2;
		cin >> name2;
		if (s.find(name2) != s.end()) { // 이름이 존재
			v.push_back(name2);
		}
	}
	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}