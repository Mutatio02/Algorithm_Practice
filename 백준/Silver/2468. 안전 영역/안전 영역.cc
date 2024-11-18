#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int board[101][101];
int visit[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// 방문 배열 초기화 함수
void clear(int size) {
    for (int i = 0; i < size; i++) {
        fill(visit[i], visit[i] + size, -1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int H = 0; // 최대 높이
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            H = max(H, board[i][j]); // 최대 높이 계산
        }
    }

    int area = 0; // 최대 안전 영역 수
    for (int h = 0; h <= H; h++) { // 높이 0부터 최대 높이까지
        clear(N); 
        int cnt = 0; 

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // 안전 영역 시작 조건
                if (board[i][j] > h && visit[i][j] == -1) {
                    cnt++; // 새로운 안전 영역 발견
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visit[i][j] = 1;

                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (board[nx][ny] <= h || visit[nx][ny] != -1) continue;
     
                            q.push({nx, ny});
                            visit[nx][ny] = 1;
                        }
                    }
                }
            }
        }

        area = max(area, cnt); 
    }

    cout << area << '\n';

    return 0;
}
