#include <bits/stdc++.h>
using namespace std;

// 25.01.23 시뮬레이션(구슬탈출2)
// -- 처음 bfs생각 그러나 구현 실패
int N, M;
string board[11];
int vis[11][11][11][11]; // 방문 여부(빨간 구슬 x,y 파란 구슬 x,y)
pair<int, int> red, blue; // 빨간 구슬 파란 구슬의 좌표
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
    queue<tuple<int,int,int,int>> q;
    q.push({red.first,red.second,blue.first,blue.second});
    vis[red.first][red.second][blue.first][blue.second] = 0;
    
    while(!q.empty()) {
        int rx,ry,bx,by;
        tie(rx,ry,bx,by) = q.front();
        q.pop();
        int cnt = vis[rx][ry][bx][by];
        if(cnt>=10) return -1;

        for(int i=0; i<4; i++) {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            // 파란색 구슬 기울이기
            while(board[nbx+dx[i]][nby+dy[i]] == '.') {
                nbx += dx[i];
                nby += dy[i];
            } 
            // 파란 구슬이 구멍에 들어가면 실패
            if(board[nbx+dx[i]][nby+dy[i]] == 'O') continue;

            // 빨간색 구슬 기울이기
            while(board[nrx+dx[i]][nry+dy[i]] == '.') {
                nrx += dx[i];
                nry += dy[i];
            }
            // 빨간 구슬이 구멍에 들어가면 성공
            if(board[nrx+dx[i]][nry+dy[i]] == 'O') return cnt+1;
            
            // 빨강 파랑 구슬이 겹치는 경우 늦게 도착한 것은 1칸 뒤로 돌아가기
            if((nrx==nbx)&&(nry==nby)) {
                if(i==0) {
                    (ry<by) ? nry-- : nby--;
                }
                else if(i==1) {
                    (rx<bx) ? nrx-- : nbx--;
                }
                else if(i==2) {
                    (ry>by) ? nry++ : nby++;
                }
                else {
                    (rx>bx) ? nrx++ : nbx++;
                }
            }

            if(vis[nrx][nry][nbx][nby] != -1) continue;
            vis[nrx][nry][nbx][nby] = cnt+1;
            q.push({nrx,nry,nbx,nby});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // -1 로 배열 초기화
    for(int i=0; i<11; i++) { 
        for(int j=0; j<11; j++) {
            for(int k=0; k<11; k++) {
                fill(vis[i][j][k],vis[i][j][k]+11,-1);
            }
        }
    }
    
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> board[i];
        for(int j=0; j<M; j++) {
            if(board[i][j] == 'B') {
                blue = {i,j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'R') {
                red = {i,j};
                board[i][j] = '.';
            }
        }
    }

    cout << bfs();
    return 0;
}
