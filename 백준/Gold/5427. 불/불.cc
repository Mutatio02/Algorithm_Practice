#include <bits/stdc++.h>
using namespace std;
// 24.12.29 --불 복습
char board[1001][1001];
int vis[1001][1001];
int fire[1001][1001];

int T,w,h;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while(T--) {
        cin >> w >> h;
        queue<pair<int,int>> que;
        queue<pair<int,int>> f;
        bool escape = false;

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> board[i][j];
                vis[i][j] = -1;
                fire[i][j] = -1; // 초기화

                if(board[i][j] == '@') {
                    que.push({i,j});
                    vis[i][j] = 0; // 방문 시작
                }

                if(board[i][j] == '*') {
                    f.push({i,j});
                    fire[i][j] = 0; // 불 시작
                }
            }
        }

        while(!f.empty()) {
            auto cur = f.front();
            f.pop();

            for(int i=0; i<4; i++) {
                int nx = dx[i] + cur.first;
                int ny = dy[i] + cur.second;

                if(nx<0 || nx >= h || ny<0 || ny>=w) continue;
                if(board[nx][ny] == '#' || fire[nx][ny] != -1) continue;
                fire[nx][ny] = fire[cur.first][cur.second]+1;
                f.push({nx,ny});
            }
        }

        while(!que.empty() && !escape) {
            auto cur = que.front();
            que.pop();
            
            for(int i=0; i<4; i++) {
                int nx = dx[i] +cur.first;
                int ny = dy[i] +cur.second;

                if(nx<0 || nx >= h || ny<0 || ny >= w) {
                    cout << vis[cur.first][cur.second]+1 << "\n";
                    escape = true;
                    break;
                }

                if(board[nx][ny] == '#' || vis[nx][ny] != -1 ) continue;
                if(fire[nx][ny] != -1 && vis[cur.first][cur.second]+1 >= fire[nx][ny]) continue;
                vis[nx][ny] = vis[cur.first][cur.second]+1;
                que.push({nx,ny});
            }
        }

        if(!escape) {
            cout << "IMPOSSIBLE" << "\n";
        }
    }
}
