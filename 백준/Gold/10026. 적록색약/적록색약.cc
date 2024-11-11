#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

char board[101][101];
bool visit[101][101];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int N;
void BFS(int i,int j) {
    queue<pair<int,int>> que;
    que.push({i,j});
    visit[i][j] = true;
    
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 || nx >=N || ny<0 || ny >=N) continue; // 범위를 지나면 무시
            if(visit[nx][ny]) continue; // 이미 방문했으면 무시
            if(board[cur.first][cur.second] != board[nx][ny] ) continue; // 인접한 부분이 같지 않으면 무시 (같아야지 탐색)
            que.push({nx,ny});
            visit[nx][ny] = true;
        }
    }
}
int area() {
    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visit[i][j]) {
                BFS(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }
    int res1 = area(); // 정상인 경우

    for(int i=0; i<N; i++) { // 방문 배열 초기화
        fill(visit[i],visit[i] +N ,false);
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == 'G') { // 적록색약의 경우 R과 G를 같다고 인식
                board[i][j] = 'R';
            }
        }
    }

    int res2 = area();
    
    cout << res1 << " " << res2;
    return 0;
}
