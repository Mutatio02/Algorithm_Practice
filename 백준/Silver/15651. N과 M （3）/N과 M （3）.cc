#include <bits/stdc++.h>
using namespace std;
// 25.01.06 백트레킹 복습 (N과M 2)
int N,M;
int board[10];

void back_track(int k) {
    if(k == M) {
        for(int i=0; i<M; i++) {
            cout << board[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=N; i++) {
        board[k] = i;
        back_track(k+1);
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    back_track(0);

    
    return 0;
}