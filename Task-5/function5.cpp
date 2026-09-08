#include <iostream>
#include "function5.h"
using namespace std;
void pascalTriangle(int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        long v = 1;
        for(int j=0; j<=i; j++){
            cout << v << " ";
            v = v * (i-j)/(j+1);
        }
        cout << endl;
    }
}