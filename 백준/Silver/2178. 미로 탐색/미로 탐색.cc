#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
// 24.11.09 복습 -- 미로찾기
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
string board[101];
int visit[101][101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> board[i];
    }

    queue<pair<int,int>> que;
    que.push({0,0});
    visit[0][0] = 1;

    while(!que.empty()) {
        auto cur = que.front();
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 || nx >= N || ny<0 || ny>=M)    continue; // 범위 지나면 무시
            if(board[nx][ny] == '0'|| visit[nx][ny] != 0) continue;

            que.push({nx,ny});
            visit[nx][ny] = visit[cur.first][cur.second] + 1;
        }
    }
    cout << visit[N-1][M-1];

    return 0;
}
