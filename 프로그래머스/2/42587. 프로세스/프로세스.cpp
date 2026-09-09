#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<int> prio, idx;
	for (int i = 0; i < priorities.size(); i++) {
		prio.push(priorities[i]);
		idx.push(i);
	}

	while (!prio.empty()) {
		int max_prio_idx = max_element(priorities.begin(), priorities.end()) - priorities.begin();
		int temp = prio.front(), temp_idx = idx.front();
		prio.pop();
		idx.pop();
		if(temp == priorities[max_prio_idx]) {
			answer++;
			if(temp_idx == location)
				return answer;
			priorities.erase(priorities.begin() + max_prio_idx);
		}
		else {
			prio.push(temp);
			idx.push(temp_idx);
		}
	}
	return answer;
}