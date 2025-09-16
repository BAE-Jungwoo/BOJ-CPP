#include <iostream>
using namespace std;

int main() {
	int total_card;
	int target;
	cin >> total_card >> target;

	int* card = new int[total_card];
	int sum = 0;

	for (int i = 0; i < total_card; i++) {
		cin >> card[i];
	}

	for(int j = 0; j < total_card; j++) {
		for(int k = j + 1; k < total_card; k++){
			for(int l = k + 1; l < total_card; l++){
				int temp_sum = card[j] + card[k] + card[l];
				if(temp_sum <= target && temp_sum > sum){
					sum = temp_sum;
				}
			}
		}
	}
	cout << sum << endl;

	delete[] card;
	return 0;
}