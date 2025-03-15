#include <bits/stdc++.h>
using namespace std;
// 25.03.15 노드사이의 거리 (트리)
int N,M;
vector<pair<int,int>> adj[1005]; 
bool vis[1005];

int bfs(int start,int end) {
    fill(vis,vis+N+1,false);
    queue<pair<int,int>> q;
    q.push({start,0}); // 시작 노드 거리
    vis[start] = true;

    while(!q.empty()) {
        auto [cur,dist] = q.front();
        q.pop();
        
        if(cur==end) return dist; // cur가 탐색을 지나면서 end를 만나면 거리 리턴

        for(auto[nxt,d] : adj[cur]) {
            if(vis[nxt]) continue;
            vis[nxt] = true;
            q.push({nxt,dist+d}); // 거리 누적하기
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for(int i=0; i<N-1; i++) {
        int u,v,d;
        cin >> u >> v >> d;
        adj[u].push_back({v,d}); // 시작,끝,거리
        adj[v].push_back({u,d}); // 연결
    }
    
    while(M--) {
        int u,v;
        cin >> u >> v;
        cout << bfs(u,v) << "\n";        
    }

    return 0;
}
