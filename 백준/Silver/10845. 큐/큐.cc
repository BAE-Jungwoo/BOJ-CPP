#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Queue {
private:
	int q[10001];
	int f = 0;
	int b = 0;
	int count = 0;

public:
	void push(int x) {
		q[b] = x;
		b = (b + 1) % 10001;
		count++;
	}

	int pop() {
		if (empty())
			return -1;
		int temp = q[f];
		f = (f + 1) % 10001;
		count--;
		return temp;
	}

	int size() {
		return count;
	}

	int empty() {
		if (count == 0) {
			return 1;
		}
		return 0;
	}

	int front() {
		if (empty())
			return -1;
		return q[f];
	}

	int back() {
		if (empty())
			return -1;
		return q[b - 1];
	}
};

int main()
{
	int inst;
	vector<int> ans;
	cin >> inst;
	cin.ignore();

	Queue q;
	for (int i = 0; i < inst; i++) {
		string command;
		getline(cin, command);

		if (command.substr(0, 4) == "push") {
			int x = stoi(command.substr(5));
			q.push(x);
		}
		else if (command == "pop")
			ans.push_back(q.pop());
		else if (command == "size")
			ans.push_back(q.size());
		else if (command == "empty")
			ans.push_back(q.empty());
		else if (command == "front")
			ans.push_back(q.front());
		else if (command == "back")
			ans.push_back(q.back());
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	return 0;
}