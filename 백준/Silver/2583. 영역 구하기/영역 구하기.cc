#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
// 24.11.20--영역 구하기 복습

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int visit[101][101];
int board[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M,N,K;
    cin >> M >> N >> K;
    vector<int> v;
    int cnt = 0;
    for(int i=0; i<K; i++) {
        pair<int,int> left;
        pair<int,int> right;
        cin >> left.first >> left.second >> right.first >> right.second;

        for(int p = left.second; p<right.second; p++) {
            for(int q = left.first; q<right.first; q++) {
                board[p][q] = -1;
            }
        }
    }
    queue<pair<int,int>> q;

    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == -1 || visit[i][j] == 1) continue;
            q.push({i,j});
            visit[i][j] = 1;
            cnt++;
            int area = 1; // 영역 넓이

            while(!q.empty()) {
                auto cur = q.front();
                q.pop();

                for(int dir =0; dir<4; dir++) {
                    int nx = dx[dir]+cur.first;
                    int ny = dy[dir]+cur.second;

                    if(nx<0 || nx>= M || ny<0 || ny>= N) continue;
                    if(board[nx][ny] == -1|| visit[nx][ny] == 1) continue;
                    visit[nx][ny] = 1;
                    q.push({nx,ny});
                    area++;
                }
            }
            v.push_back(area);
        }
    }

    sort(v.begin(),v.end());
    
    cout << cnt << "\n";
    for(int r : v) {
        cout << r << ' ';
    }

    return 0;
}
