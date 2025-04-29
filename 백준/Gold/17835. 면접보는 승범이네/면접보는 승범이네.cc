#include <bits/stdc++.h>
using namespace std;

// 25.04.29 면접보는 승범이네 (다익스트라)
int N,M,K;
const int MX = 100005;
const long long INF = 1e18;
vector<pair<long long,int>> adj[MX];
long long dist[MX];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    fill(dist+1,dist+N+1,INF);    
    
    while(M--) {
        int u,v,c;
        cin >> u >> v >> c;
        adj[v].push_back({c,u}); // 단방향 연결 --> 원래 u -> v 연결이지만 
        // v -> u 반대로 접근(V ElogE) 
    }    

    for(int i=0; i<K; i++) {
        int city;
        cin >> city;
        dist[city] = 0;
        pq.push({dist[city],city}); // 거리 정점        
    }

    while(!pq.empty()) {
        auto [cost,cur] = pq.top();
        pq.pop();
        
        if(dist[cur]!=cost) continue;
        for(auto [nxtcost,nxt] : adj[cur]) {
            if(dist[nxt] > dist[cur]+nxtcost) { // 기존 거리 > 현재거리 + 간선비용 
                dist[nxt] = dist[cur]+nxtcost;
                pq.push({dist[nxt],nxt});
            }
        }
    }

    int citynumber = 0;
    long long ansdist = -1;
    for(int i=1; i<=N; i++) {
        if(dist[i]>ansdist) {
            ansdist = dist[i];
            citynumber = i;
        }
    }
    cout << citynumber << "\n" << ansdist;

    return 0;
}
