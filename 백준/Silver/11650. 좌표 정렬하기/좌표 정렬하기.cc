#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Point {
	int x;
	int y;
};

bool compare(Point& a, Point& b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main() {
	int N;
	vector<Point> v;
	cin >> N;

	for (int i = 0; i < N; i++) {
		Point p;
		cin >> p.x >> p.y;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), compare);

	for (const auto& p : v) {
		cout << p.x << " " << p.y << "\n";
	}
}