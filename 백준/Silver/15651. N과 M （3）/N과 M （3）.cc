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

    for(int i=1; i<=N; i++) {
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
