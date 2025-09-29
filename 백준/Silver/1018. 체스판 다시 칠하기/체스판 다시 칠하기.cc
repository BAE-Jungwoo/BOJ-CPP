#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<char>> arr(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int min_repaint = 64; // Maximum repaint
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int repaint_w = 0; // Starting with 'W'
			int repaint_b = 0; // Starting with 'B'
			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					if ((x + y) % 2 == 0) { // Even position
						if (arr[i + x][j + y] != 'W') repaint_w++;
						if (arr[i + x][j + y] != 'B') repaint_b++;
					} else {				// Odd position
						if (arr[i + x][j + y] != 'B') repaint_w++;
						if (arr[i + x][j + y] != 'W') repaint_b++;
					}
				}
			}
			min_repaint = min(min_repaint, min(repaint_w, repaint_b));
		}
	}
	cout << min_repaint << endl;
}