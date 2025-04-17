#include <bits/stdc++.h>
using namespace std;

// 25.04.17 파티 (다익스트라)
int N,M,X;
int dist[1005];
vector<pair<int,int>> adj[1005];
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
const int INF = 1e9;

int solve(int start,int end) {
    fill(dist,dist+N+1,INF);
    dist[start] = 0;

    pq.push({dist[start],start}); // {거리,방문 노드}

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(dist[cur.second]!=cur.first) continue;
        for(auto nxt : adj[cur.second]) {
            if(dist[nxt.second]<=cur.first+nxt.first) continue;
            dist[nxt.second] = cur.first + nxt.first;
            pq.push({dist[nxt.second],nxt.second});
        }
    }

    return dist[end];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X; // X는 시작점

    for(int i=0; i<M; i++) {
        int u,v,t;
        cin >> u >> v >> t; // 시작 끝 비용(시간)
        adj[u].push_back({t,v}); // 시간, 방문 노드
    }

    int ans = 0;
    for(int st=1; st<=N; st++) {
        ans = max(ans,solve(st,X) + solve(X,st));
    }
    cout << ans;

    return 0;
}
