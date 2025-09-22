#include <iostream>
using namespace std;

int main() {
	int people;
	cin >> people;

	int** arr = new int* [people];
	for (int i = 0; i < people; i++) {
		arr[i] = new int[2];
	}

	for (int j = 0; j < people; j++) {
		int weight, height;
		cin >> weight >> height;
		arr[j][0] = weight;
		arr[j][1] = height;
	}

	for (int n = 0; n < people; n++) {
		int cnt = 1;
		for (int m = 0; m < people; m++) {
			if (n == m) continue;
			if (arr[n][0] < arr[m][0] && arr[n][1] < arr[m][1]) {
				cnt++;
			}	
		}
		cout << cnt << " ";
	}

	for (int k = 0; k < people; k++) {
		delete[] arr[k];
	}
	delete[] arr;
	return 0;
}