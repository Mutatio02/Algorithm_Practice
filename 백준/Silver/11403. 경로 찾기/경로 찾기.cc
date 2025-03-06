#include <bits/stdc++.h>
using namespace std;

// 25.03.06 경로 찾기 (그래프) -- 인접 행렬
int N;
int arr[105][105];
int res[105][105];
void bfs(int node) {
    bool vis[105] = {};
    queue<int> q;
    q.push(node);
    vis[node] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt=1; nxt<=N; nxt++) {
            if(arr[cur][nxt]==1) { // 간선 존재(연결 되어 있으면)
                res[node][nxt] = 1; // 경로가 존재하면 1
                if(!vis[nxt]) {
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }    

    for(int i=1; i<=N; i++) {
        bfs(i);
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cout << res[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}
