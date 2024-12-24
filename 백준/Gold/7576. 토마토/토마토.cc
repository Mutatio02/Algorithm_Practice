#include <bits/stdc++.h>
using namespace std;
// 24.12.24 복습 -- 토마토
int N,M;

int dx[4] ={0,1,0,-1};
int dy[4] ={1,0,-1,0};

int box[1001][1001];
int vis[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    queue<pair<int,int>> que;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> box[i][j];

            if(box[i][j] == 1) { // 익은 토마토 부터 시작
                que.push({i,j});
                vis[i][j] = 0; // 시작!
            }

            if(box[i][j] == 0) {
                vis[i][j] = -1; // -1로 초기화 뒤 방문 예정
            }
        }
    }

    while(!que.empty()) {
        auto cur = que.front();
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx<0 || nx>= N || ny<0 || ny>=M) continue;
            if(vis[nx][ny] != -1) continue; // -1로 초기화 된 것이 아니라면 무시

            que.push({nx,ny});
            vis[nx][ny] = vis[cur.first][cur.second] +1;
        }
    }

    int ans = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(vis[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans,vis[i][j]);
        }
    }
    cout << ans;

    return 0;
}
