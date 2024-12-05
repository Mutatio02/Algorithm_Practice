#include <bits/stdc++.h>
using namespace std;

int N,M;
int board[10];
int output[10];
bool used[10];
void solve(int k,int start) {
    if(k == M) {
        for(int i=0; i<M; i++) {
            cout << output[i] << ' ';
        }
        cout << "\n";
        return;
    }
    
    for(int i=start; i<N; i++) {
        output[k] = board[i];
        solve(k+1,i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> board[i];
    }
    sort(board,board+N);

    solve(0,0);

    return 0;
}
