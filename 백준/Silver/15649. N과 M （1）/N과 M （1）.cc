#include <bits/stdc++.h>
using namespace std;
// 25.01.03 백트레킹 복습 (N과 M)
int N,M; // N 까지의 수 M개 선택
bool used[10]; 
int board[10];
void back_track(int k) {
    if(k == M) { // 길이가 M이 되면 출력
        for(int i=0; i<M; i++) {
            cout << board[i] << ' ';
        }
        cout<< "\n";
        return;
    }
    for(int i=1; i<=N; i++) {
        if(!used[i]) { // 사용되지 않았으면
            board[k] = i; // 길이가 K일때
            used[i] = true; // i는 사용됨
            back_track(k+1); //  다음 길이 탐색 및 백트래킹
            used[i] = false; // 백트래킹으로 원상태 복귀
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M; 
    back_track(0);

    return 0;
}