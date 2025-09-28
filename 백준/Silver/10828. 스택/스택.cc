#include <iostream>
#include <vector>
#include <string>
using namespace std;

class stack {
private:
	int end = -1;
	int stack[10001];

public:
	void push(int n) {
		stack[end + 1] = n;
		end += 1;
	}

	int pop() {
		if (empty())
			return -1;
		int result = stack[end];
		end -= 1;	
		return result;
	}

	int size() {
		return end + 1;
	}

	int empty() {
		if (size() == 0)
			return 1;
		return 0;
	}

	int top() {
		if(empty())
			return -1;
		return stack[end];
	}
};

int main() {
	int inst;
	vector<int> answer;
	cin >> inst;
	cin.ignore();

	stack stk;
	for (int i = 0; i < inst; i++) {
		string str;
		getline(cin, str);

		if (str.substr(0, 4) == "push") {
			int n = stoi(str.substr(5));
			stk.push(n);
		}
		else if (str == "top") {
			answer.push_back(stk.top());
		}
		else if(str== "pop") {
			answer.push_back(stk.pop());
		}
		else if (str == "size") {
			answer.push_back(stk.size());
		}
		else if (str == "empty") {
			answer.push_back(stk.empty());
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}