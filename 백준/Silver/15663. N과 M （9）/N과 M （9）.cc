#include <bits/stdc++.h>
using namespace std;

int N,M;
int board[10];
int output[10];
bool used[10];
void solve(int k) {
    if(k == M) {
        for(int i=0; i<M; i++) {
            cout << output[i] << ' ';
        }
        cout << "\n";
        return;
    }
    int tmp = 0; // 이전과 같은 값이 아니여야 된다

    for(int i=0; i<N; i++) {
        if(!used[i] && tmp!= board[i]) {
            used[i] = true;
            output[k] = board[i];
            tmp = output[k];
            solve(k+1);
            used[i] = false;
        }    
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
