#include <bits/stdc++.h>
using namespace std;

// 25.04.08 바닥장식 (그래프)
int N,M;
char board[55][55];
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j]; 
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j]=='X') continue;
            cnt++;

            if(board[i][j]=='-') {
                for(int y=j; y<M; y++) {
                    if(board[i][y]!='-') break;
                    board[i][y] = 'X';
                }
            }
            else if(board[i][j]=='|') {
                for(int x=i; x<N; x++) {
                    if(board[x][j]!='|') break;
                    board[x][j] = 'X';
                }
            }
        }
    }

    cout << cnt;

    return 0;
}

