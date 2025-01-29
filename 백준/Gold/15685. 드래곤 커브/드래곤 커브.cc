#include <bits/stdc++.h>
using namespace std;
// 25.1.29 시뮬레이션(드래곤 커브)
int N;
int x,y,d,g;
int board[105][105];
int ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--) {
        cin >> x >> y >> d >> g; // 시작좌표 방향 세대
        vector<int> v; 
        v.push_back(d); // 방향 넣기
        board[y][x] = 1; // 시작점 좌표는 반대로

        while(g--) {
            int dsize = v.size();

            for(int i = dsize-1; i>=0; i--) {
                v.push_back((v[i]+1)%4); // 반시계 방향으로 90도 회전
            }
        }
     
        for(int i=0; i<v.size(); i++) {
            int dir = v[i];

            if(dir==0) x++; 
            else if(dir==1) y--;
            else if(dir==2) x--;
            else y++;

            board[y][x] = 1; // 이동한 곳 표시
        }
    }

    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(board[i][j] && board[i][j+1] && board[i+1][j] && board[i+1][j+1]) {
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}
