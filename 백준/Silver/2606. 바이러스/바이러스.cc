#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, bool visited[], vector<int> graph[], int& count) {
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next]) {
			count++;
			dfs(next, visited, graph, count);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, pair;
	bool visited[101] = { false, }; // 방문 여부
	vector<int> graph[101];

	int n1, n2;
	int count = 0;
	cin >> N >> pair;

	for (int i = 0; i < pair; i++) {
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	dfs(1, visited, graph, count);
	cout << count;
	return 0;
}