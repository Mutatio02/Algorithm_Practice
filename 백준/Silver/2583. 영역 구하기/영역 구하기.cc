#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int board[101][101];
int visit[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M,N,K;
    cin >> M >> N >> K;
    vector<int> result;
    int cnt = 0;

    queue<pair<int,int>> q;
    for(int i=0; i<K; i++) {
        pair<int,int> left;
        pair<int,int> right;
        cin >> left.first >> left.second >> right.first >> right.second;
        for(int i=left.second; i<right.second; i++) {
            for(int j=left.first; j<right.first; j++) {
                board[i][j] = -1; // 갈 수 없는 부분은 -1
            }
        }
    }
    
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == -1 || visit[i][j] == 1) continue; // 이미 방문했거나 가지 못하면
            q.push({i,j});
            visit[i][j] = 1; // 방문은 1로 표시
            int area = 1;
            cnt++; // 새로운 지역 발견시 증가
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = dx[dir] + cur.first;
                    int ny = dy[dir] + cur.second;

                    if(nx<0 || nx >= M || ny<0 ||ny >=N) continue;
                    if(board[nx][ny] == -1 || visit[nx][ny] == 1) continue;
                    visit[nx][ny] = 1;
                    q.push({nx,ny});
                    area++;
                }
                
            }
            result.push_back(area);
        }
    }
    sort(result.begin(),result.end());

    cout << cnt << "\n";
    for(int r : result) {
        cout << r << " ";
    }

    return 0;
}
