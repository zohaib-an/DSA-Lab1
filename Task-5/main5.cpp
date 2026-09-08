#include <iostream>
#include "function5.h"
using namespace std;
int main(){
    cout << "n=0 " << endl;
    pascalTriangle(0);
    cout << endl;
    cout << "n=1 " << endl; 
    pascalTriangle(1);
    cout << endl;
    cout << "n=5 " << endl;
    pascalTriangle(5);
    cout << endl;
    return 0;
}