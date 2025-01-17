#include <bits/stdc++.h>
using namespace std;

int board[4][5][5][5]; // board[방향][판의 순서][5][5]
int maze[5][5][5]; // board에서 생성할 임의의 집합
int dz[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> q;

int solve() {
    int dist[5][5][5]= {0,}; // 거리 계산
    if(maze[0][0][0]==0 || maze[4][4][4]==0) return 9999;

    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    dist[0][0][0] = 1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int dir=0; dir<6; dir++) {
            int nz = dz[dir] + get<0>(cur);
            int nx = dx[dir] + get<1>(cur);
            int ny = dy[dir] + get<2>(cur);

            if(nz<0 || nz>=5 || nx<0 || nx>=5 || ny<0 || ny>=5) continue;
            if(maze[nz][nx][ny] ==0 || dist[nz][nx][ny] !=0) continue;
            if(nz==4 && nx==4 && ny==4) {
                return dist[get<0>(cur)][get<1>(cur)][get<2>(cur)];
            }
            dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            q.push({nz,nx,ny});
        }
    }
    return 9999;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                cin >> board[0][i][j][k]; // 입력
            }
        }

        for(int j=0; j<5; j++) { // 1번째는 0번의 90도 회전
            for(int k=0; k<5; k++) {
                board[1][i][j][k] = board[0][i][4-k][j];
            }
        }

        for(int j=0; j<5; j++) { // 2번째는 1번의 90도 회전(0을기준 180)
            for(int k=0; k<5; k++) {
                board[2][i][j][k] = board[1][i][4-k][j];
            }
        }

        for(int j=0; j<5; j++) { // 3번째는 2번의 90도 회전(0을기준 270)
            for(int k=0; k<5; k++) {
                board[3][i][j][k] = board[2][i][4-k][j];
            }
        }
    }


    int arr[5] = {0,1,2,3,4};
    int ans = 9999;
    do {
        for(int tmp=0; tmp<1024; tmp++) {
            int brute = tmp;
            for(int i=0; i<5; i++) {
                int dir = brute%4;
                brute/=4;
                for(int j=0; j<5; j++) {
                    for(int k=0; k<5; k++) {
                        maze[i][j][k] = board[dir][arr[i]][j][k];
                    }
                }
            }
            ans = min(ans,solve());
        }
    }while(next_permutation(arr,arr+5));
    
    if(ans == 9999) {
        ans = -1;
    }
    
    cout << ans;
    return 0;
}
