#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

int box[1001][1001]; // 상자
int visit[1001][1001]; // 방문 표시
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M,N;
    cin >> M >> N; // 가로 세로
    queue<pair<int,int>> que;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) { // 토마토가 익은부분부터 시작
                que.push({i,j});
                visit[i][j] = 0; 
            }

            if(box[i][j] == 0) { // 익지 않은 토마토는 -1로 초기화
                visit[i][j] = -1; // -1로 초기화 --> 후에 방문 해야됨
            }
        }
    }

    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx<0 || nx >= N || ny<0 || ny>=M)    continue; // 범위를 지나가면 무시
            if(visit[nx][ny]!=-1)   continue; // 익지 않은 토마토 이외의 나머지는 무시
            visit[nx][ny] = visit[cur.first][cur.second]+1;
            que.push({nx,ny});
        }
    }
    
    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(visit[i][j] == -1) { // 아직까기 익지않은 토마토가 있으면
                cout << -1;
                return 0;
            }
            ans = max(ans,visit[i][j]);
        }
    }

    cout << ans;
    
    return 0;
}
