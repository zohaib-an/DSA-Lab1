#include <iostream>
#include <vector>
#include "function3.h"
using namespace std;

void printV(vector<int>& v){
    cout << "{";
    for(int num:v){
        cout << num << " ";
    }
    cout << "}";
}

int main(){
    int arr1[] = {1, 2, 3, 2, 5, 2};
    int k1 = 2;
    vector<int> res1 = findIndices(arr1, 6, k1);
    cout << "Test case 1: Multiple occurances: ";
    printV(res1);
    cout << endl;

    int arr2[] = {1, 2, 3, 4, 5};
    int k2 = 0;
    vector<int> res2 = findIndices(arr2, 5, k2);
    cout << "Test case 2: Key not present";
    printV(res2);
    cout << endl;

    int arr3[1] = {};
    int k3 = 3;
    vector<int> res3 = findIndices(arr3, 0, k3);
    cout << "Test case 3: null array ";
    printV(res3);
    return 0;
}
