#include <bits/stdc++.h>
using namespace std;
// 24.12.25 복습 -- 불!
int R,C;

int dx[4] ={0,1,0,-1};
int dy[4] ={1,0,-1,0};

char maze[1001][1001];
int fire[1001][1001]; // 불
int vis[1001][1001]; // 지훈
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    for (int i=0; i<R; i++) {
        fill(fire[i], fire[i]+C, -1);
        fill(vis[i], vis[i]+C, -1);
    }
    queue<pair<int,int>> que;
    queue<pair<int,int>> f;
    int time = 0;
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> maze[i][j];

            if(maze[i][j] == 'J') {
                que.push({i,j});
                vis[i][j] = 1;
            }
            if(maze[i][j] == 'F') {
                f.push({i,j});
                fire[i][j] = 1;
            }
        }
    }

    while(!f.empty()) {
        auto cur = f.front();
        f.pop();

        for(int i=0; i<4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
            if(maze[nx][ny] == '#' || fire[nx][ny]!=-1) continue;
            fire[nx][ny] = fire[cur.first][cur.second]+1;
            f.push({nx,ny});
        }
    }

    while(!que.empty()) {
        auto cur = que.front();
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx<0 || nx>=R || ny<0 || ny>=C) { // R과 C의 범위를 넘어서면 탈출
                cout << vis[cur.first][cur.second];
                return 0;
            }
            if(maze[nx][ny] == '#' || vis[nx][ny] !=-1) continue;
            if(fire[nx][ny] !=-1 && fire[nx][ny] <= vis[cur.first][cur.second]+1) continue;
            
            vis[nx][ny] = vis[cur.first][cur.second] +1;
            que.push({nx,ny});
        }
    }
    
    cout << "IMPOSSIBLE";

    return 0;
}
