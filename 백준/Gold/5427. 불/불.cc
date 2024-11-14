#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char board[1001][1001];
int visit[1001][1001];
int fire[1001][1001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int w,h;
        cin >> w >> h; // 너비와 높이
        queue<pair<int,int>> q; // 상근
        queue<pair<int,int>> f; // 불
        bool escape = false;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> board[i][j];
                visit[i][j] = -1;
                fire[i][j] = -1; 

                if(board[i][j] == '*') { // 불
                    f.push({i,j});
                    fire[i][j] = 0;
                }
                else if(board[i][j] == '@') { // 시작 위치
                    q.push({i,j});
                    visit[i][j] = 0;
                }
            }
        }

        while(!f.empty()) {
            auto cur = f.front();
            f.pop();

            for(int dir = 0; dir<4; dir++) {
                int nx = dx[dir] + cur.first;
                int ny = dy[dir] + cur.second;

                if(nx<0 || nx >= h || ny<0 || ny >= w) continue;
                if(board[nx][ny] =='#' || fire[nx][ny] != -1) continue;
                fire[nx][ny] = fire[cur.first][cur.second] +1;
                f.push({nx,ny});
            }
        }
        
        while(!q.empty() && !escape) { // 탈출할 때 까지
            auto cur = q.front();
            q.pop();
            
            for(int dir = 0; dir<4; dir++) {
                int nx = dx[dir] + cur.first;
                int ny = dy[dir] + cur.second;

                if(nx<0 || nx >= h || ny<0 || ny>= w)  {
                    cout << visit[cur.first][cur.second] + 1 << "\n";
                    escape = true;
                    break;
                }
                if(visit[nx][ny] != -1 || board[nx][ny] == '#') continue; // 이미 방문한 경우
                if(fire[nx][ny] != -1 && fire[nx][ny]<=visit[cur.first][cur.second]+1) continue; // 이미 빨리 도착한 경우 
                
                visit[nx][ny] = visit[cur.first][cur.second] +1;
                q.push({nx,ny});
            }
        }
        if(!escape) {
            cout << "IMPOSSIBLE" << "\n";
        }

    }
    
    return 0;
}
