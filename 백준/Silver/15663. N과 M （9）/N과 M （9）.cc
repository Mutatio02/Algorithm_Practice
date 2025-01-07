#include <bits/stdc++.h>
using namespace std;
// 25.01.07 백트레킹 복습 (N과M 9)
int N,M;
int board[10];
int output[10];
bool used[10];

void back_track(int k) {
     if(k==M) {
        for(int i=0; i<M; i++) {
            cout << output[i] << ' ';
        }
        cout << "\n";
        return;
    }

    int compare = 0;
    for(int i=0; i<N; i++) {
        if(!used[i] && compare != board[i]) { // 중복 방지
            output[k] =  board[i];
            compare = board[i];
            used[i] = true;
            back_track(k+1);
            used[i] = false;  // 백트래킹 복귀
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
    
    back_track(0);

    return 0;
}