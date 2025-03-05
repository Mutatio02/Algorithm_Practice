#include <bits/stdc++.h>
using namespace std;

// 25.03.05 결혼식 (그래프) -- 인접 리스트
int N,M;
vector<int> arr[1005];
bool vis[1005];
int cnt = 0;

void bfs() { // dfs가 아니라 bfs로 풀이(깊이가 존재)
    queue<pair<int,int>> q;
    q.push({1,0});
    vis[1] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if(depth>=2) continue;

        for(auto nxt : arr[cur]) {
            if(vis[nxt]) continue;
            cnt++;
            vis[nxt] = true;
            q.push({nxt,depth+1});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> M;
    while(M--) {
        int u,v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for(int i=1; i<=N; i++) {
        sort(arr[i].begin(),arr[i].end());
    }

    bfs();

    cout << cnt;

    return 0;
}
