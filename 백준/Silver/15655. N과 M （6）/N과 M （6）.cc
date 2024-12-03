#include <bits/stdc++.h>
using namespace std;

int N,M;
int board[10];
int arr[10];

void solve(int k) {
    if(k ==M) {
        for(int i=0; i<M; i++) {
            cout << board[arr[i]] << ' ';
        }
        cout << "\n";
        return;
    }

    int start = 0;
    if(k!=0) start = arr[k-1] + 1;

    for(int i= start; i<N; i++) {
        arr[k] = i;
        solve(k+1);
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
    
    solve(0);

    return 0;
}
