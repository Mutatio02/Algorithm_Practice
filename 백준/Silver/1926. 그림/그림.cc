#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// 2024.11.05 복습
int p[501][501]; // 그림
bool visit[501][501];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M; // 세로 가로

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> p[i][j];
        }
    }
    int cnt = 0; // 그림개수
    int pic = 0; // 그림 넓이
    queue<pair<int,int>> que;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(p[i][j] ==0 || visit[i][j]) continue;
            cnt++;
            que.push({i,j});
            visit[i][j] = 1;
            int area = 0;
            while(!que.empty()) {
                auto cur = que.front();
                que.pop();
                area++;

                for(int j=0; j<4; j++) {
                    int nx = cur.first + dx[j];
                    int ny = cur.second + dy[j];

                    if(nx<0|| nx >=N || ny<0 || ny>=M) continue;
                    if(p[nx][ny] == 0 || visit[nx][ny] == 1) continue;

                    que.push({nx,ny});
                    visit[nx][ny] = 1;
                }
            }
            pic = max(area,pic);
        }
    }
    cout << cnt << "\n" << pic;
    return 0;
}
