#include <iostream>
#include <string>
#include <vector>
#include <cctype>
// #include <algorithm>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; // 포켓몬의 개수
	int M; // 맞춰야 하는 문제의 개수
	cin >> N >> M;

	vector<string> v;
	map<string, int> mp; // 포켓몬 이름과 번호를 매핑
	for(int i = 0; i < N; i++){
		string s; 
		cin >> s; 
		v.push_back(s);
		mp[s] = i + 1;
	}
	
	for (int j = 0; j < M; j++) {
		string answer;
		cin >> answer;

		if (isdigit(answer[0])) { // 숫자인 경우
			int index = stoi(answer) - 1;
			cout << v[index] << "\n";
		}
		else { // 문자인 경우
			/* O(N) 탐색
			int x = find(v.begin(), v.end(), answer) - v.begin();
			cout << x + 1 << "\n";
			*/
			cout << mp[answer] << "\n"; // O(log N) or O(1) 탐색
		}
	}
	return 0;
}