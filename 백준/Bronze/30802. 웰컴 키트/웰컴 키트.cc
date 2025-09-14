#include <iostream>
using namespace std;

int main() {
	int number; // 참가자 수
	int small, medium, large, x_large, xx_large, xxx_large; // 각 사이즈별 참가자 수
	int tshirt, pen; // 티셔츠와 펜의 묶음 수

	cin >> number;
	cin >> small >> medium >> large >> x_large >> xx_large >> xxx_large;
	cin >> tshirt >> pen;

	int total_tshirt = 0;
	total_tshirt += (small + tshirt - 1) / tshirt;
	total_tshirt += (medium + tshirt - 1) / tshirt;
	total_tshirt += (large + tshirt - 1) / tshirt;
	total_tshirt += (x_large + tshirt - 1) / tshirt;
	total_tshirt += (xx_large + tshirt - 1) / tshirt;
	total_tshirt += (xxx_large + tshirt - 1) / tshirt;

	cout << total_tshirt << endl;

	int max_pen = number / pen;
	int min_pen = number % pen;
	cout << max_pen << " " << min_pen << endl;

	return 0;
}