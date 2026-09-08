#include <iostream>
#include "function4.h"
using namespace std;
int main(){
    string x1 = "Hello World!";
    string p1 = "Hello";
    cout << "Pattern found at position " << findPattern(p1, x1) << endl;

    string x2 = "Data Structures and Algorithms";
    string p2 = "thms";
    cout << "Pattern found at position " << findPattern(p2, x2) << endl;

    string x3 = "ABCDEFG";
    string p3 = "XX";
    cout << findPattern(p3, x3) << endl;

    string x4;
    string p4;
    cout << findPattern(p4, x4);
}