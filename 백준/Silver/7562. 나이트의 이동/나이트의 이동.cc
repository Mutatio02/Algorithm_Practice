#include <iostream>
#include <queue>
#include <string>
using namespace std;
// 24.11.19 -- 나이트 이동 복습
int board[301][301];
int dx[8] = {1 , 2, -1, -2, -1, -2, 1, 2};
int dy[8] = {2 , 1, -2, -1, 2, 1, -2,-1};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int l;
        cin >> l;
        queue<pair<int,int>> q;
        for(int i=0; i<l; i++) {
            for(int j=0; j<l; j++) {
                board[i][j] = -1;
            }
        }
        
        pair<int,int> loc;
        pair<int,int> mov;
        cin >> loc.first >> loc.second;
        cin >> mov.first >> mov.second;

        if(loc == mov) {
            cout << 0 << '\n';
            continue;
        }

        q.push({loc.first,loc.second});
        board[loc.first][loc.second] = 0;

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            for(int dir = 0; dir<8; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx<0 || nx >= l || ny<0 || ny >= l) continue;
                if(board[nx][ny] >= 0) continue;
                board[nx][ny] = board[cur.first][cur.second] +1;
                q.push({nx,ny});
            }
        }
        cout << board[mov.first][mov.second] << '\n';

    }
    return 0;
}
