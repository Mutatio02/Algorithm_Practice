#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int board[1001][1001];
bool visit[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            board[i][j] = 0;
        }
        visit[i] = false;
    }

    int N,M; // 정점 간선
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        int u,v;
        cin >> u >> v;
        board[u][v] = 1;
        board[v][u] = 1;
    }
    int cnt = 0;

    for(int i=1; i<=N; i++) {
        if(visit[i] == false) {
            queue<int> que;
            que.push(i);
            visit[i] = true;

            while(!que.empty()) {
                int cur = que.front();
                que.pop();

                for(int j=1; j<=N; j++) {
                    if(board[cur][j] == 1 && visit[j] == false) {
                        que.push(j);
                        visit[j] = true;
                    }
                }
            }
            cnt++;
        }
    }
    cout << cnt;
    
    return 0;
}
