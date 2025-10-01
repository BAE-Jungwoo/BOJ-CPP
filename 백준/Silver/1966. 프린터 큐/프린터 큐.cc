#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	vector<int> result;
	cin >> num; // 테스트 케이스의 개수

	for (int i = 0; i < num; i++) {
		int N, M;
		cin >> N >> M; // 문서의 개수 & 궁금한 문서의 위치

		vector<int> v;
		for (int j = 0; j < N; j++) {
			int imp;
			cin >> imp; // 문서의 중요도
			v.push_back(imp);
		}

		int count = 0;
		while (1) {
			int max = -1; // 중요도의 최댓값
			for (int m = 0; m < v.size(); m++) {
				if (v[m] > max) {
					max = v[m];
				}
			}
			
			if (v.front() == max) { // 중요도가 가장 높은 문서가 맨 앞에 있는 경우
				count++;
				v.erase(v.begin());
				if (M == 0) { // 궁금한 문서가 출력된 경우
					result.push_back(count);
					break;
				}
				M--;
			}
			else { // 중요도가 가장 높은 문서가 맨 앞에 없는 경우
				int temp = v.front();
				v.erase(v.begin());
				v.push_back(temp);
				if (M == 0) { // 궁금한 문서가 맨 뒤로 간 경우
					M = v.size() - 1;
				}
				else
					M--;
			}
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}