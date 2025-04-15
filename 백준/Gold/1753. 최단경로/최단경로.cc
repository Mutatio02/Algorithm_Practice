#include <bits/stdc++.h>
using namespace std;

// 25.04.15  (다익스트라)
int V,E;
int K;
vector<pair<int,int>> adj[20005];
int dist[20005];

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    cin >> K;

    fill(dist,dist+V+1,INF);

    while(E--) {
        int u,v,w;
        cin >> u >> v >> w; // 간선과 가중치
        adj[u].push_back({w,v}); // 가중치 간선
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // 최소힙 {거리,시작점}

    dist[K] = 0; // 시작 정점 거리는 0
    pq.push({dist[K],K}); // 거리, 시작정점

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(cur.first != dist[cur.second]) continue;
        for(auto nxt : adj[cur.second]) {
            if(dist[nxt.second] <= dist[cur.second]+nxt.first) continue;
            dist[nxt.second] = dist[cur.second]+nxt.first;
            pq.push({dist[nxt.second],nxt.second});
        }
    }
    for(int i=1; i<=V; i++) {
        if(dist[i]==INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    
    return 0;
}
