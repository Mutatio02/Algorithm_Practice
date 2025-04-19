#include <bits/stdc++.h>
using namespace std;

// 25.04.18 최소비용 구하기 (다익스트라)
int N,M;
int st,ed;
vector<pair<int,int>> adj[1005];
int dist[1005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fill(dist,dist+N+1,INF);
    cin >> M;

    for(int i=0; i<M; i++) {
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({c,v}); // 비용 정점
    }   
    cin >> st >> ed;
    
    dist[st] = 0;
    pq.push({dist[st],st}); // 거리 정점
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(dist[cur.second]!= cur.first) continue;
        for(auto nxt : adj[cur.second]) {
            if(dist[nxt.second] <= dist[cur.second]+nxt.first) continue;
            dist[nxt.second] = dist[cur.second]+nxt.first;
            pq.push({dist[nxt.second],nxt.second});
        }
    }
    
    cout << dist[ed];

    return 0;
}
