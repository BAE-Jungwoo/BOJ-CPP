#include <vector>
using namespace std;

void dfs(int fatigue, vector<vector<int>>& dungeons, vector<bool>& visited, int cnt, int& answer) {
	if (answer < cnt)
		answer = cnt;

	for (int j = 0; j < dungeons.size(); j++) {
		if (visited[j])
			continue;

		if (dungeons[j][0] <= fatigue) {
			visited[j] = true;
			dfs(fatigue - dungeons[j][1], dungeons, visited, cnt + 1, answer);
			visited[j] = false;	 // 원상복구
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = 0;
	vector<bool> visited(dungeons.size(), false);
	dfs(k, dungeons, visited, 0, answer);
	return answer;
}