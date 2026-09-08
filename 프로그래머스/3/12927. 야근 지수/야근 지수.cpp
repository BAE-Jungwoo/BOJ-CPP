#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
	priority_queue<int> pq;
	for (int i = 0; i < works.size(); i++)
		pq.push(works[i]);

    while(n > 0) {
		if (pq.top() == 0) return 0;
		int top = pq.top() - 1;
		pq.pop();
		pq.push(top);
		n--;
	}

	while(!pq.empty()) {
		answer += 1LL * (pq.top() * pq.top());
		pq.pop();
	}
	return answer;
}