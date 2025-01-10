#include <bits/stdc++.h>
using namespace std;
// 25.01.09 시뮬레이션(2048 easy 복습)
int N;
int board[21][21];
int board2[21][21];
int ans = 0;
void rotate() {
    int copy[21][21];

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            copy[i][j] = board2[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            board2[i][j] = copy[N-1-j][i];
        }
    }
}

void move(int dir) {
    dir%=4;
    while(dir--) rotate(); // 0도 90도 180도 270도에 맞춰서 회전
    for(int i =0; i<N; i++) {
        int res[21] = {};
        int idx= 0;
        for(int j=0; j<N; j++) { // 기울였을 때 계산
            if(board2[i][j] == 0 ) continue;
            if(res[idx]==0)  {
                res[idx] = board2[i][j];
            }
            else if(res[idx] == board2[i][j]) {
                res[idx++] *=2;
            }
            else {
                res[++idx] = board2[i][j];
            }
        }
        for(int j=0; j<N; j++) { // 기울인 행 계산 결과를 다시 담기
            board2[i][j] = res[j];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }

    for(int tmp =0; tmp<1024; tmp++) { // 경우의 수는 총 4의 5승
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                board2[i][j] = board[i][j];
            }
        }

        int search = tmp;
        for(int i=0; i<5; i++) { // 최대 5번
            int dir = search%4;
            search/=4;
            move(dir);
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                ans = max(ans,board2[i][j]);
            }
        }
    }

    cout << ans;
    
    
    return 0;
}