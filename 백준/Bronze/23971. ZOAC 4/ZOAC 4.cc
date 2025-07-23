#include <bits/stdc++.h>
using namespace std;
// 25.07.24 ZOAC 4
int H,W,N,M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W >> N >> M;
    int row = (H + N) / (N+1);
    int col = (W + M) / (M+1);

    cout << row * col;
    
    return 0;
}
