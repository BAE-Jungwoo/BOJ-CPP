#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M; // 저장된 사이트 주소 수, 비번을 찾으려는 사이트 주소 수
	cin >> N >> M;

	map<string, string> mp;
	string site, pw;
	for (int i = 0; i < N; i++) {
		cin >> site >> pw;
		mp.insert(make_pair(site, pw));
	}

	vector<string> v;
	for (int j = 0; j < M; j++) {
		cin >> site;
		if (mp.find(site) != mp.end()) {
			v.push_back(mp[site]);
		}
	}

	for (const auto& it : v) {
		cout << it << "\n";
	}
	return 0;
}