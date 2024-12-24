#include <bits/stdc++.h>
using namespace std;
// 24.12.24 복습 -- 미로
int N,M;
string maze[101];
int vis[101][101];

int dx[4] ={0,1,0,-1};
int dy[4] ={1,0,-1,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    queue<pair<int,int>> que;

    for(int i=0; i<N; i++) {
        cin >> maze[i];
    }

    que.push({0,0});
    vis[0][0] = 1;

    while(!que.empty()) {
        auto cur = que.front();
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(maze[nx][ny] == '0' || vis[nx][ny] != 0) continue;
            que.push({nx,ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }

    cout << vis[N-1][M-1];

    return 0;
}
