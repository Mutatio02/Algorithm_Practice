#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int board[51][51]; // 밭
bool visit[51][51]; // 방문여부
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int M,N,K; // 가로 세로 위치 개수
        cin >> M >> N >> K;
        // 초기화
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                board[i][j] = 0;
                visit[i][j] = false;
            }
        }

        for(int i=0; i<K; i++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1; // 1은 배추가 있는 곳
        }
        queue<pair<int,int>> que;// 좌표를 담는 큐
        int cnt = 0; // 배추 묶음
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(board[i][j] == 1 && visit[i][j] == false) { // 배추가 있는데 방문하지 않은 경우
                    cnt++;
                    que.push({i,j});
                    visit[i][j] = true;

                    while(!que.empty()) {
                        auto cur = que.front();
                        que.pop();

                        for(int i = 0; i<4; i++) {
                            int nx = cur.first + dx[i];
                            int ny = cur.second + dy[i];

                            if(nx<0 || nx >= N || ny <0 || ny >=M)  continue; // 범위를 지나가면 무시

                            if(board[nx][ny] == 1 && visit[nx][ny] == false) { // 주위에 배추가 있는데 방문하지 않은 경우
                                visit[nx][ny] = true;
                                que.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        cout << cnt<< '\n';
    
    }
    return 0;
}
