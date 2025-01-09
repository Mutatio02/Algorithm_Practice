#include <bits/stdc++.h>
using namespace std;
// 25.01.08 시뮬레이션(감시)
int N,M;
int board[10][10]; // 원본
int board2[10][10]; // 복사본
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pair<int,int>> cctv;
int ans = INT_MAX;

void solve(int x,int y, int dir) {
    dir%= 4;
    while(1) {
        x = x+dx[dir];
        y = y+dy[dir];

        if(x<0 || x>=N || y<0 || y>=M) return; // 범위 벗어날시 탈출
        if(board2[x][y] == 6) return; // 벽이면 탈출
        if(board2[x][y] !=0) continue; // 빈공간이 아니면 무시
        board2[x][y] = -1; // -1로 표시 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];

            if(board[i][j]!=0 && board[i][j]!=6) {
                cctv.push_back({i,j}); // cctv 좌표 넣기
            }
        }
    }

    for(int tmp=0; tmp< (1 << 2* cctv.size()); tmp++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                board2[i][j] = board[i][j];
            }
        }

        int search = tmp;

        for(int i=0; i<cctv.size(); i++) {
            int dir = search%4;
            search /= 4;

            int x = cctv[i].first;
            int y = cctv[i].second;

            if(board[x][y] == 1) {
                solve(x,y,dir);
            }
            else if(board[x][y]==2) {
                solve(x,y,dir);
                solve(x,y,dir+2);
            }
            else if(board[x][y]==3) {
                solve(x,y,dir);
                solve(x,y,dir+1);
            }
            else if(board[x][y]==4) {
                solve(x,y,dir);
                solve(x,y,dir+1);
                solve(x,y,dir+2);
            }
            else {
                solve(x,y,dir);
                solve(x,y,dir+1);
                solve(x,y,dir+2);
                solve(x,y,dir+3);
            }
        }
        
        int cnt = 0; // 경우의 수 마다 개수 세기
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(board2[i][j] ==0) {
                    cnt++;
                }
            }
        }
        ans = min(ans,cnt);
    }
    
    cout << ans;

    return 0;
}