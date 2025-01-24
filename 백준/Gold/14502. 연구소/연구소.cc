#include <bits/stdc++.h>
using namespace std;
// 25.01.23 시뮬레이션(연구소)
// 내 생각: 벽을 미리 세워둔 다음 바이러스를 bfs로 전파한뒤 탐색(구현 실패)
int N,M;
int board[9][9];
int tmp[9][9]; // 복사본
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int area = 0;

void bfs() {
    queue<pair<int,int>> q;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(tmp[i][j]==2) {
                q.push({i,j});
            }
        }
    } 

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int dir=0; dir<4; dir++) {
            int nx = dx[dir]+cur.first;
            int ny = dy[dir]+cur.second;

            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(tmp[nx][ny]!=0) continue;
            tmp[nx][ny] = 2;
            q.push({nx,ny});
        }
    }
}
int calcul() {
    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(tmp[i][j]==0) cnt++;
        }
    }
    return cnt;
}
void wall(int cnt) { // 벽세우기

    if(cnt==3) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                tmp[i][j] = board[i][j]; // 시뮬레이션을 위해 복사
            }
        }
        
        bfs(); // 바이러스 전파
        
        area = max(area,calcul());
        return;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] == 0) {
                board[i][j] = 1;
                wall(cnt+1); // 백트래킹
                board[i][j] = 0;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }

    wall(0);

    cout << area;

    return 0;
}
