#include <bits/stdc++.h>
using namespace std;

int N,M;
int board[10];
int output[10];

void solve(int k,int start) { // 인덱스와 시작점
    if(k == M) {
        for(int i=0; i<M; i++) {
            cout << output[i] << ' ';
        }
        cout << "\n";
        return;
    }
    
    int tmp = 0; // 중복 확인
    for(int i=start; i<N; i++) {
        if(tmp!= board[i]) {
            output[k] = board[i];
            tmp = board[i];
            solve(k+1,i); 
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

    solve(0,0);

    return 0;
}
