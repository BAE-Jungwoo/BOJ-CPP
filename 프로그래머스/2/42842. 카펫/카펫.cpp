#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
	int half = (brown - 4) / 2;
	int row = 0, col = 0, cnt = 0;

	while(row * col != yellow) {
		col = (half / 2) - cnt;
		row = (half - (half / 2)) + cnt;
		cnt++;
	}
	answer.push_back(row + 2);
	answer.push_back(col + 2);
	return answer;
}