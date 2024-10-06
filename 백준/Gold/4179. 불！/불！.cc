#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

char wall[1001][1001];
int visit[1001][1001];
int fire_time[1001][1001];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R,C;
    cin >> R >> C;
    queue<pair<int,int>> que;
    queue<pair<int,int>> fire;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> wall[i][j];

            if(wall[i][j] == 'F') { // 불이 났으면
                fire_time[i][j] = 1; // 불이 난 위치 표시
                fire.push({i,j});
            }
            else if(wall[i][j] == 'J') { // 시작 위치를 찾으면
                visit[i][j] = 1; // 시작위치 표시
                que.push({i,j});
            }
            else { // 이외의 경우는 해당 없음
                visit[i][j]= 0;
                fire_time[i][j] = 0;
            }
        }
    }

    // 불 먼저
    while(!fire.empty()) {
        auto cur = fire.front();
        fire.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 || nx >=R || ny <0 || ny>=C) // 불이 범위를 넘어갔으면 무시
                continue;
            if(wall[nx][ny] == '#' || fire_time[nx][ny] != 0) // 벽이거나 이미 불이 났으면 무시
                continue;
            fire_time[nx][ny] = fire_time[cur.first][cur.second] +1;
            fire.push({nx,ny});
        }
    }

    // 탈출
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 || nx >=R || ny <0 || ny>=C) { // 탈출에 성공했다면
                cout << visit[cur.first][cur.second]; // 출력
                return 0;
            }

            if(wall[nx][ny] == '#' || visit[nx][ny] != 0) // 벽이거나 이미 방문 했으면 무시
                continue;
            if(fire_time[nx][ny] != 0 && fire_time[nx][ny] <= visit[cur.first][cur.second] +1)
                continue;

            visit[nx][ny] = visit[cur.first][cur.second] +1;
            que.push({nx,ny});
        }
    }
    // 탈출 못했을 경우
    cout << "IMPOSSIBLE";

    return 0;
}
