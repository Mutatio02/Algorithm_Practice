#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arr[15][15] = {0};
    for(int i=0; i<15; i++) {
        arr[0][i] = i;
    }


    for(int i=1; i<15; i++) {
        for(int j=1; j<15; j++) {
            arr[i][j] = arr[i][j-1] + arr[i-1][j];
        }
    }

    int T;
    cin >> T;

    while(T--) {
        int k,n; // k층 n호
        cin >> k >> n;
        cout << arr[k][n] << '\n';
    }
    return 0;
}