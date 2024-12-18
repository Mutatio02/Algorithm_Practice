#include <bits/stdc++.h>
using namespace std;
// 2048(easy) --> 다시 풀기 24.12.18
int N;
int board[21][21]; // 2048판
int board2[21][21]; // 판의 복사본

void rotate() {
    int tmp[21][21]; // 판의 회전을 위한 복사본
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tmp[i][j]= board2[i][j];
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            board2[i][j] = tmp[N-1-j][i];
        }
    }
}
void tilt(int dir) {
    while(dir--) rotate(); // 0, 90, 180, 270 회전 
    for(int i=0; i<N; i++) { // 회전한 결과를 더하기
        int tilted[21] = {};
        int idx = 0;
        for(int j=0; j<N; j++) {
            if(board2[i][j] == 0) continue;
            if(tilted[idx] == 0) {
                tilted[idx] = board2[i][j];
            }
            else if(tilted[idx] == board2[i][j]) {
                tilted[idx++] *=2;
            }
            else {
                tilted[++idx] = board2[i][j];
            }
        }
        for(int j=0; j<N; j++) { // 더한 결과를 다시 담기
            board2[i][j] = tilted[j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int big = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }

    for(int tmp=0; tmp<1024; tmp++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                board2[i][j] = board[i][j];
            }
        }
        int search = tmp;
        for(int i =0; i<5; i++) { // 최대 5회
            int dir = search%4;
            search/=4;
            tilt(dir);
        }
        for(int i=0; i<N; i++) { // board2에서 가장 큰 값을 찾기
            for(int j=0; j<N; j++) {
                big = max(big,board2[i][j]); 
            }
        }       
    }
    cout << big;
    return 0;
}
