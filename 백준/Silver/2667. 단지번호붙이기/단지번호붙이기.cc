#include <bits/stdc++.h>
using namespace std;
// 24.12.30 --단지번호 붙이기 복습

int N;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
string board[26];
bool vis[26][26];
vector<int> v;

void bfs(int x,int y) {
    int tower = 0;
    queue<pair<int,int>> que;
    que.push({x,y});
    vis[x][y] = true;

    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        tower++;

        for(int i=0; i<4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(board[nx][ny]=='0' || vis[nx][ny]) continue;
            que.push({nx,ny});
            vis[nx][ny] = true;
        }
    }
    v.push_back(tower);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> board[i];
    }
    int cnt = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++ ) {
            if(board[i][j] !='0' && !vis[i][j]) {
                bfs(i,j);
                cnt++;
            }
        }
    }

    sort(v.begin(),v.end());

    cout << cnt << "\n";
    for(auto t : v) {
        cout << t << "\n";
    }

    return 0;
}
