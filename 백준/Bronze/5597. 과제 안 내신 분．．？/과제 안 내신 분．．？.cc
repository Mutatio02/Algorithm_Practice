#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int std[30] = {0};

    for(int i=0; i<28; i++) {
        int n;
        cin >> n;
        std[n-1] = n;
    }

    for(int i=0; i<30; i++) {
        if(std[i] == 0) {
            cout << i+1 << '\n';
        }
    }
    return 0;
}
