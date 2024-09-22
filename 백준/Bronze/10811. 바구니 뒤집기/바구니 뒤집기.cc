#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mod[42] = {0};

    int N,M;
    cin >> N >> M;

    vector<int> v(N);

    for(int i=0; i<N; i++) {
        v[i] = i+1;
    }

    for(int p=0; p<M; p++) {
        int i,j;
        cin >> i >> j;

        reverse(v.begin() + i-1, v.begin()+j);
    }

    for (int n : v) {
        cout << n << " ";
    }
    return 0;
}
