#include "function4.h"
using namespace std;
int findPattern(string p, string x){
    int a = p.length();
    int b = x.length();
    if(a==0) return 0;
    if(b<a) return -1;
    for(int i=0; i<=b-a; i++){
        if(x[i]==p[0]){
            bool found = true;
            for(int j=1; j<a; j++){
                if(p[j]!=x[i+j]){
                    found = false;
                    break;
                }
            }
            if(found) return i;
        }

    }
    return -1;
}