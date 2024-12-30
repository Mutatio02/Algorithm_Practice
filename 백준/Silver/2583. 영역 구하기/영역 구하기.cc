#include <bits/stdc++.h>
using namespace std;
// 24.12.230 --영역 구하기 복습

int N,M,k;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int board[101][101];
bool vis[101][101];
vector<int> v;
void bfs(int x,int y) {
    int area = 0;
    queue<pair<int,int>> que;
    que.push({x,y});
    vis[x][y] = true;

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        area++;

        for(int i=0; i<4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx<0 || nx >= M || ny < 0 || ny>=N) continue;
            if(board[nx][ny] != 0 || vis[nx][ny]) continue;
            que.push({nx,ny});
            vis[nx][ny] = true;
        }
        
    }
    v.push_back(area);
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> k;
    int cnt = 0;
    
    while(k--) {
        pair<int,int> d1,d2;
        cin >> d1.first >> d1.second >> d2.first >> d2.second;

        for(int i=d1.second; i<d2.second; i++) {
            for(int j=d1.first; j<d2.first; j++) {
                board[i][j] = 1; // 1로 표시
            }
        }
    }
        
    
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == 0 && !vis[i][j]) {
                bfs(i,j);
                cnt++;
            }
        }
    }
    
    sort(v.begin(),v.end());

    cout << cnt << "\n";
    for(auto a : v) {
        cout << a << " ";
    }

}
