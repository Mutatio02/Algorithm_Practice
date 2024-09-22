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
    
    vector<int> v(N);

    for(int i=0; i<N; i++) {
        v[i] = i+1;
    }

    for(int p=0; p<M; p++) {
        int i,j;
        cin >> i >> j;
        swap(v[i-1],v[j-1]);
    }

    for(const int n : v) {
        cout << n << " ";
    }
    return 0;
}
