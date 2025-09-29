#include <iostream>
using namespace std;

int main() {
	int N, K; // N명의 사람, K번째 사람
	cin >> N >> K;

	int* arr = new int[N];
	for(int i = 0; i < N; i++) {
		arr[i] = i + 1; 
	}

	int idx = 0;
	cout << "<";
	while (N > 0) {
		idx = (idx + K - 1) % N; 
		cout << arr[idx];
		if(N != 1) 
			cout << ", ";
		for(int i = idx; i < N - 1; i++) { // idx 이후의 사람들을 앞으로 당김
			arr[i] = arr[i + 1];
		}
		N--;
	}
	cout << ">";
	delete[] arr;
	return 0;
}