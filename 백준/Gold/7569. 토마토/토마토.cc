#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int box[101][101][101];
int visit[101][101][101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, H; // 가로(M), 세로(N), 높이(H)
    cin >> M >> N >> H;
    queue<tuple<int, int, int>> que; // BFS

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int tmp;
                cin >> tmp;
                box[i][j][k] = tmp;

                if (tmp == 1) { // 익은 토마토면
                    que.push({i, j, k});
                    visit[i][j][k] = 1; // 방문 표시
                } else if (tmp == 0) { // 익지 않은 토마토면
                    visit[i][j][k] = -1; // 아직 방문하지 않음
                }
            }
        }
    }

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue; // 범위 밖 체크
            if (visit[nx][ny][nz] != -1) continue; // 이미 방문한 경우 무시

            visit[nx][ny][nz] = visit[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            que.push({nx, ny, nz});
        }
    }

    int result = 0;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visit[i][j][k] == -1) { // 익지 않은 토마토가 남아있는 경우
                    cout << -1;
                    return 0;
                }
                result = max(result, visit[i][j][k]);
            }
        }
    }

    cout << result - 1; // 시작을 1로 표시했으므로 결과에서 1을 빼줌
    return 0;
}
