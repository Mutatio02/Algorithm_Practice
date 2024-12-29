#include <bits/stdc++.h>
using namespace std;
// 24.12.29 --나이트 이동 복습
int T,I;
int board[301][301];

int dx[8] = {1,2,1,2,-1,-2,-1,-2};
int dy[8] = {2,1,-2,-1,2,1,-2,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while(T--) {
        cin >> I;
        pair<int,int> loc;
        pair<int,int> mov;
        queue<pair<int,int>> que;

        cin >> loc.first >> loc.second;
        cin >> mov.first >> mov.second;

        for(int i=0; i<I; i++) {
            for(int j=0; j<I; j++) {
                board[i][j] = -1; // -1로 초기화
            }
        }

        if(loc == mov) {
            cout << 0 << "\n";
            continue;
        }
        
        que.push({loc.first,loc.second});
        board[loc.first][loc.second] = 0; // 0으로 시작

        while(!que.empty()) {
            auto cur = que.front();
            que.pop();

            for(int i=0; i<8; i++) {
                int nx = dx[i] + cur.first;
                int ny = dy[i] + cur.second;

                if(nx<0 ||nx>= I || ny<0 || ny >= I) continue;
                if(board[nx][ny]>=0) continue;
                board[nx][ny] = board[cur.first][cur.second]+1;
                que.push({nx,ny});
            }
        }
        cout << board[mov.first][mov.second] << "\n";
    }
    

    return 0;
}
