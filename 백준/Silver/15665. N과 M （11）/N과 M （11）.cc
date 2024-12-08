#include <bits/stdc++.h>
using namespace std;

int N,M;
int board[10];
int output[10];

void solve(int k) {
    if(k == M) {
        for(int i=0; i<M; i++) {
            cout << output[i] << ' ';
        }
        cout << "\n";
        return;
    }

    int tmp = 0; // 이전을 저장
    for(int i=0; i<N; i++) {
        if(board[i] != tmp) { // 중복이 아니라면
            output[k] =board[i]; 
            tmp = output[k]; // 이전을 복사
            solve(k+1);
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
