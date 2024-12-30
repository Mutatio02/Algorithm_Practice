#include <bits/stdc++.h>
using namespace std;
// 24.12.30 -- 안전영역 복습

int N;
int board[101][101];
bool vis[101][101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y, int limit) {
    queue<pair<int, int>> que;
    que.push({x, y});
    vis[x][y] = true; 

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] <= limit || vis[nx][ny]) continue; // limit(height) 보다 작은 경우 무시

            vis[nx][ny] = true;  
            que.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int height = 0;  // 최대 높이
    int cnt = 0;     // 최대 안전영역 개수

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            height = max(height, board[i][j]);
        }
    }

    for (int h = 0; h <= height; h++) {
        int area = 0; 

        for (int i = 0; i < N; i++) {
            fill(vis[i], vis[i] + N, false);  // 초기화 --> 높이에 따라 달라지기 때문
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] > h && !vis[i][j]) {  // 방문하지 않고 안전영역(높이보다 큰 경우)
                    bfs(i, j, h);
                    area++;  // 하나의 영역이 확정됨
                }
            }
        }

        cnt = max(area, cnt);
    }

    cout << cnt;  

    return 0;
}
