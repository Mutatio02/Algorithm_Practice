#include <bits/stdc++.h>
using namespace std;

int L, R, C; // 빌딩의 층수, 행과 열
int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

char board[31][31][31];
int vis[31][31][31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        queue<tuple<int, int, int>> que;
        bool escaped = false;

        // 초기화
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    vis[i][j][k] = -1;
                }
            }
        }

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S') {
                        que.push({i, j, k});
                        vis[i][j][k] = 0;
                    }
                }
            }
        }

        while (!que.empty() && !escaped) {
            int z, x, y;
            tie(z, x, y) = que.front();
            que.pop();

            for (int i = 0; i < 6; i++) {
                int nz = z + dz[i];
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (board[nz][nx][ny] == '#' || vis[nz][nx][ny] >= 0) continue;

                if (board[nz][nx][ny] == 'E') {
                    cout << "Escaped in " << vis[z][x][y] + 1 << " minute(s).\n";
                    escaped = true;
                    break;
                }

                vis[nz][nx][ny] = vis[z][x][y] + 1;
                que.push({nz, nx, ny});
            }
        }

        if (!escaped) {
            cout << "Trapped!\n";
        }
    }

    return 0;
}
