#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<int> v(N,0);
    for(int p=0; p<M; p++) {
        int i,j,k;
        cin >> i >> j >> k;

        for(int q = i-1; q<j; q++) {
            v[q] = k;
        }
    }

    for(int n : v) {
        cout << n <<" ";
    }

    return 0;
}
