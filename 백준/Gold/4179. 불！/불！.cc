#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
// 24.11.10 -- 복습
using namespace std;

int dx[4]= {0,1,0,-1};
int dy[4] = {1,0,-1,0};

char board[1001][1001];
int visit[1001][1001];
int fire[1001][1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R,C;
    cin >> R >> C;

    queue<pair<int,int>> q;
    queue<pair<int,int>> f;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> board[i][j];

            if(board[i][j] == 'J') { // 초기위치 방문
                q.push({i,j});
                visit[i][j] = 1; // 방문표시
            }
            else if(board[i][j] == 'F') { // 불난 위치 
                f.push({i,j});
                fire[i][j] = 1; // 불난 표시
            }
            else {
                visit[i][j] = 0;
                fire[i][j] = 0;
            }
        }
    }

    while(!f.empty()) {
        auto cur = f.front();
        f.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 || nx>=R || ny<0 || ny >= C) continue;
            if(board[nx][ny] == '#' || fire[nx][ny] != 0) continue; // 불의 위치가 벽이거나 이미 이미 방문한 것은 무시한다.

            fire[nx][ny] = fire[cur.first][cur.second] +1;
            f.push({nx,ny});
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 || nx>=R || ny<0 || ny >= C) { // 범위를 지나간 것은 통과에 성공한 것이다.
                cout << visit[cur.first][cur.second];
                return 0;
            }
            if(board[nx][ny] == '#' || visit[nx][ny] != 0) continue; // 방문 위치가 벽이거나 이미 방문한 것은 무시한다.
            if(fire[nx][ny] != 0 && fire[nx][ny] <= visit[cur.first][cur.second] +1) continue; 
            // 이미 불이 번졌거나 도착 시점과 불의 위치 전파 위치가 같은 경우는 무시한다.
            
            visit[nx][ny] = visit[cur.first][cur.second] +1;
            q.push({nx,ny});
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
