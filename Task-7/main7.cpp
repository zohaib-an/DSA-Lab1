#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "function7.h"
using namespace std;

void printMatrix(const vector<vector<int>>& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    // Test Case 1
    cout << "--- Test Case 1: 2x2 Matrix ---" << endl;
    vector<vector<int>> A1 = {{1, 2}, {3, 4}};
    vector<vector<int>> B1 = {{5, 6}, {7, 8}};
    vector<vector<int>> res1 = strassenMultiply(A1, B1);
    cout << "Strassen Output:" << endl;
    printMatrix(res1);
    cout << endl;
    // Test Case 2
    cout << "--- Test Case 2: 4x4 Matrix ---" << endl;
    vector<vector<int>> A2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7}
    };
    vector<vector<int>> B2 = {
        {7, 6, 5, 4},
        {3, 2, 1, 0},
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    vector<vector<int>> res2 = strassenMultiply(A2, B2);
    cout << "Strassen Output:" << endl;
    printMatrix(res2);
    cout << endl;
    // Test Case 3
    cout << "--- Test Case 3: Random Values Comparison ---" << endl;
    srand(time(0));
    int size = 4;
    vector<vector<int>> A3(size, vector<int>(size));
    vector<vector<int>> B3(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A3[i][j] = rand() % 10;
            B3[i][j] = rand() % 10;
        }
    }
    vector<vector<int>> resStandard = standardMultiply(A3, B3);
    vector<vector<int>> resStrassen = strassenMultiply(A3, B3);
    bool match = true;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (resStandard[i][j] != resStrassen[i][j]) {
                match = false;
                break;
            }
        }
    }
    if (match) {
        cout << "Comparison Result: Both Strassen and Standard produced identical results!" << endl;
    } else {
        cout << "Comparison Result: Mismatch detected!" << endl;
    }
    return 0;
}