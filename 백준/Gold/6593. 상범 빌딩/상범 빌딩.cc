#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char board[31][31][31];
int visit[31][31][31];

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int L, R, C;
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0) break;

        queue<tuple<int, int, int>> q;

        // 초기화
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    visit[i][j][k] = -1;
                }
            }
        }

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S') {
                        q.push({i, j, k});
                        visit[i][j][k] = 0; // 시작 위치의 방문 시간은 0
                    }
                }
            }
        }

        bool escaped = false;

        while (!q.empty() && !escaped) {
            auto cur = q.front();
            q.pop();

            for (int dir = 0; dir < 6; dir++) {
                int nz = get<0>(cur) + dz[dir];
                int nx = get<1>(cur) + dx[dir];
                int ny = get<2>(cur) + dy[dir];

                // 범위 체크 및 방문 여부 확인
                if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (board[nz][nx][ny] == '#' || visit[nz][nx][ny] >= 0) continue;

                if (board[nz][nx][ny] == 'E') {
                    cout << "Escaped in " << visit[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1 << " minute(s).\n";
                    escaped = true;
                    break;
                }

                visit[nz][nx][ny] = visit[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                q.push({nz, nx, ny});
            }
        }

        if (!escaped) {
            cout << "Trapped!\n";
        }
    }

    return 0;
}
