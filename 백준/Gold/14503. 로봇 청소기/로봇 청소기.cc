#include <bits/stdc++.h>
using namespace std;
// 25.01.18 시뮬레이션(로봇 청소기) 
int N,M;
int room[51][51];
int clean[51][51]; // 청소여부
int r,c,d;
int dx[4] = {-1,0,1,0}; // 북동남서
int dy[4] = {0,1,0,-1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> room[i][j]; // 0인 경우 빈칸, 1인 경우 벽 존재
        }
    }
    int ans = 0;

    while(true) {
        if(clean[r][c]==0) { // 청소가 안되면
            clean[r][c] = 1; // 청소완료
            ans++;
        }

        bool cleaned = false;
        for(int i=0; i<4; i++) {
            d = (d+3)%4;
            int nx = r+dx[d];
            int ny = c+dy[d];

            if(room[nx][ny]==0 && clean[nx][ny]==0) {
                r = nx;
                c = ny;
                cleaned = true;
                break;
            }
        }
        if(!cleaned) {
            int nx = r-dx[d];
            int ny = c-dy[d];

            if(room[nx][ny] ==1) break;
            r = nx;
            c = ny;
        }
    }
    cout << ans;
    return 0;
}
