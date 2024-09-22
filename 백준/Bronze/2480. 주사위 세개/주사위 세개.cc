#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a == b && b == c) {
        cout << 10000 + a * 1000;
    }
    else if(a == b|| b==c || a== c) {
        if(a==b || a==c) {
            cout << 1000 + a * 100;
        }
        else {
            cout << 1000 + b * 100;
        }
    }
    else {
        int max = a;
        if(b>max){
            max = b;
        }
        
        if(c>max) {
            max = c;
        }
        cout << max * 100;
    }
    return 0;
}
