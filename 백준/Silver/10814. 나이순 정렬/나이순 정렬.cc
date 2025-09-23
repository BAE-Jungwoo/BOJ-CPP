#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Member {
	int age;
	string name;
	int order;
};

bool compare(Member& a, Member& b) {
	if (a.age == b.age) {
		return a.order < b.order; // 나이가 같으면 가입순서대로
	}
	return a.age < b.age; // 나이순으로 정렬
}

int main() {
	int N, age;
	string name;
	cin >> N;

	vector<Member> v;

	for (int i = 0; i < N; i++) {
		Member m;
		cin >> m.age >> m.name;
		m.order = i; // 가입 순서
		v.push_back(m);
	}

	// stable_sort(v.begin(), v.end(), compare); // Merge sort로 한번에 가능
	sort(v.begin(), v.end(), compare); 

	for (const auto& m : v) {
		cout << m.age << " " << m.name << "\n";
	}

	return 0;
}