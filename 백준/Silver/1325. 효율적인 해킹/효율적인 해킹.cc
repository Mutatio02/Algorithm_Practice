#include <bits/stdc++.h>
using namespace std;

// 25.03.08 효율적인 해킹 (그래프) 
int N,M;
vector<int> adj[10005]; // 인접 리스트
int cnt[10005]; // 각 컴퓨터에서 해킹 할 수 있는 최대 수

int bfs(int node) {
    bool vis[10005];
    fill(vis+1,vis+N+1,false);  
    queue<int> q;
    q.push(node);
    vis[node] = true;
    int sum = 1; // node번호를 넣고 탐색하면서 해킹 시작하기 때문에 1
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]) {
            if(vis[nxt]) continue;
            sum++;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
    
    return sum; // 해킹 가능한 컴퓨터 수
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int u,v;
        cin >> u >> v;
        adj[v].push_back(u); // b를 해킹하면 a도 해킹 가능하다
    }

    int limit = 0;
    for(int i=1; i<=N; i++) {
        cnt[i] = bfs(i);
        limit = max(limit,cnt[i]);
    }
    

    for(int i=1; i<=N; i++) {
        if(cnt[i] == limit) cout << i << ' ';
    }
    

    return 0;
}
