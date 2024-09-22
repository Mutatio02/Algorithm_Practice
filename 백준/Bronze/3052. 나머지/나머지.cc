#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mod[42] = {0};

    int n;
    for(int i=0; i<10; i++) {
        cin >> n;
        mod[n%42]++;
    }

    int count = 0;
    for(int m : mod) {
        if(m >0) {
            count++;
        }
    }
    cout << count;
    
    return 0;
}
