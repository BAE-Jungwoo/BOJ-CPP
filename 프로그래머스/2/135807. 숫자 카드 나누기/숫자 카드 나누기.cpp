#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) { // 반복문을 이용한 최대공약수
    int mod = a % b;
    while (mod > 0) {
        a = b;
        b = mod;
        mod = a % b;
    }

    return b;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int a = 0;
    int condition1 = 0;
    sort(arrayA.begin(), arrayA.end()); // arrayA 배열을 오름차순으로
    sort(arrayB.begin(), arrayB.end()); // arrayB 배열을 오름차순으로

    if (arrayA.size() == 1) { // 카드가 1개일 때
        a = arrayA[0];
    }
    else if (arrayA.size() == 2) { // 카드가 2개일 때
        a = gcd(arrayA[1], arrayA[0]);
    }
    else { // 카드가 3개 이상일 때
        a = gcd(arrayA[1], arrayA[0]);
        int tmp = 2;
        while (1) {
            a = gcd(arrayA[tmp], a);
            tmp++;
            if (tmp == arrayA.size()) {
                break;
            }
        }
    }

    if (a > 1) {
        for (int i = 0; i < arrayB.size(); i++) {
            // arrayB의 원소 중에 arrayA의 최대공약수로 나누어진 경우
            if (arrayB[i] % a == 0) { 
                condition1 = 1;
                break;
            }
        }
    }
    else { // arrayA의 최대공약수가 1 이하인 경우
        condition1 = 1;
    }

    int b = 0;
    int condition2 = 0;

    if (arrayB.size() == 1) { // 카드가 1개일 때
        b = arrayB[0];
    }
    else if (arrayB.size() == 2) { // 카드가 2개일 때
        b = gcd(arrayB[1], arrayB[0]);
    }
    else { // 카드가 3개 이상일 때
        b = gcd(arrayB[1], arrayB[0]);
        int tmp = 2;
        while (1) {
            b = gcd(arrayB[tmp], b);
            tmp++;
            if (tmp == arrayB.size()) {
                break;
            }
        }
    }

    if (b > 1) {
        for (int i = 0; i < arrayA.size(); i++) {
            // arrayA의 원소 중에 arrayB의 최대공약수로 나누어진 경우
            if (arrayA[i] % b == 0) { 
                condition2 = 1;
                break;
            }
        }
    }
    else { // arrayB의 최대공약수가 1이하인 경우
        condition2 = 1;
    }

    if (condition1 == 1 && condition2 == 1) {
        return answer;
    }
    else if (condition1 == 0 && condition2 == 1) {
        return a;
    }
    else if (condition1 == 1 && condition2 == 0) {
        return b;
    }
    else {
        return max(a, b);
    }
}