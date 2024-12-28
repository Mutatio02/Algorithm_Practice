#include <bits/stdc++.h>
using namespace std;

int M, N, H;
int box[101][101][101];
int vis[101][101][101];

int dx[6] = {0,1,-1,0,0,0};
int dy[6] = {1,0,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> H;

    queue<tuple<int, int, int>> que;

    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                int tmp;
                cin >> tmp;
                box[j][k][i] = tmp;

                if(tmp == 1) // 익은 토마토 
                    que.push({j,k,i});

                if(tmp == 0) // 익지 않은 토마토
                    vis[j][k][i] = -1; //방문X
            }
        }
    }

    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        int x,y,z;
        tie(x,y,z) = cur;

        for(int i=0; i<6; i++) {
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            int nz = dz[i]+z;

            if(nx<0||nx>=N ||ny<0||ny>=M ||nz<0 ||nz>=H) continue;
            if(vis[nx][ny][nz]>=0) continue;
            vis[nx][ny][nz] = vis[x][y][z]+1;
            que.push({nx,ny,nz});
        }
    }

    int ans = 0;
    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                if(vis[j][k][i] == -1) {
                    cout <<-1;
                    return 0;
                }
                ans = max(ans,vis[j][k][i]);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
