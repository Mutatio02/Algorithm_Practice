#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

string board[101]; // 입력
int visit[101][101]; // 미로
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,M;
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> board[i];
    } // 입력
    queue<pair<int,int>> que;
    visit[0][0] = 1;

    que.push({0,0});
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) { // 범위를 넘어가면 초기화
                continue;
            }
            if(board[nx][ny] == '0' || visit[nx][ny] != 0) {
                continue;
            }
            visit[nx][ny] = visit[cur.first][cur.second] +1;
            que.push({nx,ny});
        }
    }
    cout << visit[N-1][M-1];

    return 0;
}
