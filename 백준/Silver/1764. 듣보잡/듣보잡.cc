#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; // 듣도 못한 수, 보도 못한 수
	cin >> N >> M;
	map<string, int> mp;
	vector<string> v;
	int cnt = 0;

	while (N--) {
		string name1;
		cin >> name1;
		mp.insert(make_pair(name1, 1));
	}
	

	while (M--) {
		string name2;
		cin >> name2;
		if (mp.find(name2) != mp.end()) { // 이름이 존재
			cnt++;
			mp[name2]++;
			v.push_back(name2);
		}
		else {
			mp.insert(make_pair(name2, 1));
		}
	}
	sort(v.begin(), v.end());

	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}