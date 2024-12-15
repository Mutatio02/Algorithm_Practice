#include <bits/stdc++.h>
using namespace std;

int N, M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[10][10];  
int board2[10][10];  
vector<pair<int, int>> cctv; 

void solve(int x,int y,int dir) {
    dir = dir%4;
    while(1) {
        x = x+dx[dir];
        y = y+dy[dir];

        if(x<0 || x>=N || y<0 || y>=M) return;
        if(board2[x][y] == 6) return;
        if(board2[x][y] != 0) continue;
        board2[x][y] = -1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int cnt = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];

            if(board[i][j] != 0 && board[i][j] != 6) {
                cctv.push_back({i,j});
            }
            if(board[i][j] == 0) cnt++;
        }
    }

    for(int tmp = 0; tmp < (1 << 2*cctv.size()); tmp++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                board2[i][j] = board[i][j];
            }
        }

        int search = tmp;
        for(int i=0; i<cctv.size(); i++) {
            int dir = search%4;
            search = search/4;

            int x = cctv[i].first;
            int y = cctv[i].second;

            if(board[x][y] == 1) {
                solve(x,y,dir);
            }
            else if(board[x][y] == 2) {
                solve(x,y,dir);
                solve(x,y,dir+2);
            }
            else if(board[x][y] == 3) {
                solve(x,y,dir);
                solve(x,y,dir+1);
            }
            else if(board[x][y] == 4) {
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

        int val = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(board2[i][j]==0) val++;
            }
        }
        cnt = min(val,cnt);
    }

    cout << cnt;
    return 0;
}
