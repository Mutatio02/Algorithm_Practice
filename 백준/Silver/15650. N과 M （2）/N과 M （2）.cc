#include <bits/stdc++.h>
using namespace std;

int N,M;
int board[10];

void solve(int k) {
    if(k == M) {
        for(int i=0; i<M; i++) {
            cout << board[i] << ' ';
        }
        cout << "\n";
        return;
    }

    int start = 1;
    if(k!=0) {
        start = board[k-1] + 1; // k인 경우 K+1 부터 해당하는 수를 넣는다
    }
    for(int i=start; i<=N; i++) {
        board[k] = i;
        solve(k+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    
    solve(0);

    return 0;
}
