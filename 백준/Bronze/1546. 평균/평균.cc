#include <iostream>
using namespace std;

int main() {
	int subjects;
	float sum = 0.0, M = 0.0, avg = 0.0;
	cin >> subjects;

	float* score = new float[subjects];

	
	for (int i = 0; i < subjects; i++) {
		cin >> score[i];
		
		if (score[i] > M)
			M = score[i];
	}

	for (int i = 0; i < subjects; i++) {
		score[i] = (score[i] / M) * 100;
		sum += score[i];
	}
	avg = sum / subjects;

	cout << avg << endl;
	delete[] score;
	return 0;
}