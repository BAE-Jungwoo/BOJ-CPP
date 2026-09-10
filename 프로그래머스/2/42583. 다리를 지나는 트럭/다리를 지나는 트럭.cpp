#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int passingSum(queue<int>& passing) {
	int sum = 0;
	queue<int> temp = passing;

	while(!temp.empty()) {
		sum += temp.front();
		temp.pop();
	}
	return sum;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
	queue<int> passing, crossed;
	vector<int> time;
	int size = truck_weights.size();
	
	while (crossed.size() != size) {
		answer++;
		for (int i = 0; i < time.size(); i++) {
			time[i]--;
		}

		if (!time.empty() && time[0] == 0) {
			crossed.push(passing.front());
			passing.pop();
			time.erase(time.begin());
		}

		if (!truck_weights.empty()) {
			if (passingSum(passing) + truck_weights[0] <= weight) {
				passing.push(truck_weights[0]);
				time.push_back(bridge_length);
				truck_weights.erase(truck_weights.begin());
			}
		}
	}
	return answer;
}