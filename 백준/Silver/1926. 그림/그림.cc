#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int board[501][501] = {0};
    bool visit[501][501] = {false};
    int dx[4] = {0,-1,0,1};
    int dy[4] = {1,0,-1,0};
    int N,M;
    cin >> N >> M;

    int cnt = 0; // 그림 개수
    int big = 0; // 가장 넓은 그림

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];

        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] == 0 || visit[i][j] == true) // 색칠이 안되어 있거나 이미 방문했다면
                continue;

            cnt++; // 그림의 개수 증가 
            queue<pair<int,int>> que;
            que.push({i,j});
            visit[i][j] = true; // 방문 완료
            int area = 0; // 가장 큰 면적을 찾을 변수
            while(!que.empty()) {
                area++;
                pair<int,int> cur = que.front();
                que.pop();
                for(int dir = 0; dir <4; dir++) { // 상하좌우 탐색
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if(nx < 0 || nx >= N || ny < 0  || ny >= M) { // 탐색 범위가 넘어 갔으면
                        continue; // 무시
                    }
                    if(board[nx][ny] == 0 || visit[nx][ny] == true) { // 상하좌우 탐색이 부분이 0이거나 이미 방문했다면
                        continue; // 무시
                    }
                    
                    visit[nx][ny] = true; // 나머지는 방문 했다고 표시
                    que.push({nx,ny});
                }
            }
            big = max(big,area);
        }
    }

    cout << cnt << '\n' << big;

    return 0;
}
