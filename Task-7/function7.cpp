#include "function7.h"
#include <vector>
using namespace std;

vector<vector<int>> standardMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}
vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }
    int half = n / 2;
    vector<vector<int>> a11(half, vector<int>(half));
    vector<vector<int>> a12(half, vector<int>(half));
    vector<vector<int>> a21(half, vector<int>(half));
    vector<vector<int>> a22(half, vector<int>(half));
    vector<vector<int>> b11(half, vector<int>(half));
    vector<vector<int>> b12(half, vector<int>(half));
    vector<vector<int>> b21(half, vector<int>(half));
    vector<vector<int>> b22(half, vector<int>(half));
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + half];
            a21[i][j] = A[i + half][j];
            a22[i][j] = A[i + half][j + half];
            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + half];
            b21[i][j] = B[i + half][j];
            b22[i][j] = B[i + half][j + half];
        }
    }
    vector<vector<int>> M1 = strassenMultiply(addMatrix(a11, a22), addMatrix(b11, b22));
    vector<vector<int>> M2 = strassenMultiply(addMatrix(a21, a22), b11);
    vector<vector<int>> M3 = strassenMultiply(a11, subtractMatrix(b12, b22));
    vector<vector<int>> M4 = strassenMultiply(a22, subtractMatrix(b21, b11));
    vector<vector<int>> M5 = strassenMultiply(addMatrix(a11, a12), b22);
    vector<vector<int>> M6 = strassenMultiply(subtractMatrix(a21, a11), addMatrix(b11, b12));
    vector<vector<int>> M7 = strassenMultiply(subtractMatrix(a12, a22), addMatrix(b21, b22));
    vector<vector<int>> c11 = addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);
    vector<vector<int>> c12 = addMatrix(M3, M5);
    vector<vector<int>> c21 = addMatrix(M2, M4);
    vector<vector<int>> c22 = addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = c11[i][j];
            C[i][j + half] = c12[i][j];
            C[i + half][j] = c21[i][j];
            C[i + half][j + half] = c22[i][j];
        }
    }
    return C;
}