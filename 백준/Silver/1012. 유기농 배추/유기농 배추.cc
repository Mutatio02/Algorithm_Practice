#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// 24.11.12 -- 복습
int board[51][51];
bool visit[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int M,N,K;
        cin >> M >> N >> K;
        queue<pair<int,int>> q;
        int cnt = 0;

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                board[i][j] = 0;
                visit[i][j] =false;
            }
        }
        for(int i=0; i<K; i++) {
            int x,y;
            cin >> x >> y; // x y 좌표
            board[y][x] = 1; // 반대로
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(board[i][j] != 1 || visit[i][j]) continue;
                cnt++;

                q.push({i,j});
                visit[i][j]= true;

                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx<0 || nx >= N || ny<0 || ny >=M) continue;
                        if(board[nx][ny] != 1 || visit[nx][ny]) continue;
                        q.push({nx,ny});
                        visit[nx][ny] = true;
                    }
                }  
            }
        }
        cout << cnt << "\n";
        
    }
    return 0;
}
