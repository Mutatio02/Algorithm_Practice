#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
string board[26];
int visit[26][26];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> ans;
    int cnt = 0;
    queue<pair<int,int>> q;

    for(int i=0; i<N; i++) {
        cin >> board[i];
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == '0' || visit[i][j] >0) continue;
            q.push({i,j});
            cnt++; // 방문수 증가
            visit[i][j] = cnt; // 단지번호와 방문 수는 같다.
            int area = 0; // 영역 넓이
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                area++;
                for(int dir=0; dir<4; dir++) {
                    int nx = dx[dir] +cur.first;
                    int ny = dy[dir] +cur.second;

                    if(nx <0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(board[nx][ny] == '0' || visit[nx][ny] > 0) continue;
                    visit[nx][ny] = cnt;
                    q.push({nx,ny});
                }
            }
            ans.push_back(area);
        }
    }
    sort(ans.begin(),ans.end());
    cout << cnt << "\n";
    for(int r : ans) {
        cout << r << "\n";
    }

    return 0;
}
