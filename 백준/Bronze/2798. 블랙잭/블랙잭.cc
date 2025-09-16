#include <iostream>
using namespace std;

int main() {
	int total_card; // 전체 카드 수
	int target; // 목표 숫자
	cin >> total_card >> target;

	int* card = new int[total_card]; // 카드 배열
	int sum = 0; // 3장의 카드 합

	for (int i = 0; i < total_card; i++) {
		cin >> card[i];
	}

	for(int j = 0; j < total_card; j++) {
		for(int k = j + 1; k < total_card; k++){
			for(int l = k + 1; l < total_card; l++){
				int temp_sum = card[j] + card[k] + card[l];
				if (temp_sum <= target && temp_sum > sum) { // 3장의 카드 합이 목표 숫자 이하이고, 기존 합보다 클 때
					sum = temp_sum;
				}
			}
		}
	}
	cout << sum << endl;

	delete[] card;
	return 0;
}
