#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n = 0; // Array length variable
    int arr_num = 1; // Counter variable for elements to be pushed into the stack
    stack<int> s; // Declare a stack to store elements
    string result; // Declare a string to store the result
    cin >> n; // Input the array length

    for (int i = 1; i <= n; ++i) {
        int target = 0; // Element of the desired sequence
        cin >> target; // Input the element

        // Case1: If arr_num is less than the target, push elements into the stack until they match
        if (arr_num <= target) {
            while (arr_num <= target) {
                s.push(arr_num);
                result.push_back('+'); // Store '+' to track the number of pushes
                arr_num++;
            }
            result.push_back('-'); // After pushing all necessary elements, pop to create the "stack sequence"
            s.pop();
        }
        // Case2: If arr_num is greater than the target, pop from the stack to match the target
        else {
            if (s.top() == target) {
                result.push_back('-'); // Pop from the stack to match the target
                s.pop();
            }
            else {
                cout << "NO"; // If the target can't be matched, print "NO"
                return 0;
            }
        }
    }

    // If all operations are successful, print the result
    for (char c : result) {
        cout << c << "\n";
    }

    return 0;
}