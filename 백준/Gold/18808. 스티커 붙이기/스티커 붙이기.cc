#include <bits/stdc++.h>
using namespace std;

int board[41][41]; // 노트북
int N,M,k; // 노트북 세로, 가로, 개수
int r,c; // 행과 열
int sticker[11][11]; // 스티커

void rotate() { // 스티커의 회전전
    int copy[11][11]; // 임시 복사본
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            copy[i][j] = sticker[i][j];
        }
    }
    
    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            sticker[i][j] = copy[r-1-j][i];
        }
    }
    
    swap(r,c);
}
bool check(int x,int y) { // 노트북의 특정영역에 붙일수 있는지 체크
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(board[i+x][j+y] == 1 && sticker[i][j] == 1)
                return false;
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(sticker[i][j] == 1) {
                board[i+x][j+y] = 1; // x,y 해당영역에 붙인다는 표시
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> k;
    while(k--) {
        cin >> r >> c;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> sticker[i][j];
            }
        }
        
        for(int chance = 0; chance<4; chance++) {
            bool attach = false;
            for(int x=0; x<=N-r; x++) {
                if(attach) break;
                for(int y=0; y<=M-c; y++) {
                    if(check(x,y)) {
                        attach = true;
                        break;
                    }
                }
            }
            if(attach) break;
            rotate();
        }
    }

    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cnt += board[i][j];
        }
    }

    cout << cnt;
    return 0;
}
