#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[1005][1005];
int vis[1005][1005][2]; // [x][y][0]: 안부숨, [x][y][1]: 부숨
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            char ch;
            cin >> ch;
            arr[i][j] = ch - '0'; // 문자 입력 -> 숫자로 변환
        }
    }

    queue<tuple<int,int,int>> q;
    q.push({0,0,0}); // 시작점, 벽을 안 부순 상태
    vis[0][0][0] = 1;

    while(!q.empty()) {
        auto [x, y, broke] = q.front(); q.pop();

        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 벽이 아닌 경우
            if(arr[nx][ny] == 0 && vis[nx][ny][broke] == 0) {
                vis[nx][ny][broke] = vis[x][y][broke] + 1;
                q.push({nx, ny, broke});
            }

            // 벽이고 아직 안 부쉈을 경우
            if(arr[nx][ny] == 1 && broke == 0 && vis[nx][ny][1] == 0) {
                vis[nx][ny][1] = vis[x][y][0] + 1;
                q.push({nx, ny, 1});
            }
        }
    }

    int ans = vis[N-1][M-1][0];
    if(vis[N-1][M-1][1]) {
        if(ans == 0) ans = vis[N-1][M-1][1];
        else ans = min(ans, vis[N-1][M-1][1]);
    }

    cout << (ans == 0 ? -1 : ans) << '\n';
    return 0;
}
