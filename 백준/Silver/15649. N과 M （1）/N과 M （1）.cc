#include <bits/stdc++.h>
using namespace std;

int board[10]; // 배열에 수들을 저장해 놓기
bool IsUsed[10];// 이전으로 돌아가야 되는지 체크
int N,M;

void back_track(int k) {
    if(k == M) { // 길이가 m인 수열 완성
        for(int i=0; i<M; i++) {
            cout << board[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=N; i++) {
        if(!IsUsed[i]) { // IsUsed[i]가 사용되지 않았다면
            board[k] = i; // 저장
            IsUsed[i] = true; // 사용되었 다는 표시 남기기
            back_track(k+1); // 다음 길이 탐색
            IsUsed[i] = false; // 백트래킹으로 되돌리기
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M; // 수의 범위, 길이

    back_track(0);

    return 0;
}
