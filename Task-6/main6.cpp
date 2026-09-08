#include <iostream>
#include <vector>
#include "function6.h"
using namespace std;

void printV(const vector<int>& v) {
    cout << "{ ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << "}";
}
int main() {
    // Test Case 1
    int arr1[] = {1, 3, 2, 3, 4, 3, 5};
    vector<int> res1 = findMode(arr1, 7);
    cout << "Test case 1: Unique mode: ";
    printV(res1);
    cout << endl;

    // Test Case 2
    int arr2[] = {1, 2, 2, 3, 3, 4};
    vector<int> res2 = findMode(arr2, 6);
    cout << "Test case 2: Multiple modes: ";
    printV(res2);
    cout << endl;

    // Test Case 3
    int arr3[1] = {};
    vector<int> res3 = findMode(arr3, 0);
    cout << "Test case 3: Empty array: ";
    printV(res3);
    cout << endl;
    return 0;
}