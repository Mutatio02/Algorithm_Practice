#include <bits/stdc++.h>
using namespace std;

// 25.04.18 특정한 최단 경로 (다익스트라)

int N,E;
vector<pair<int,int>> adj[805];
int spot1,spot2; // 반드시 지나야 하는 서로다른 정점
int dist[805];
const int INF = 1e9;

long long solve(int start,int end) {
    fill(dist,dist+N+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({dist[start],start});

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(dist[cur.second]!=cur.first) continue;
        for(auto nxt : adj[cur.second]) {
            if(dist[nxt.second] <= dist[cur.second]+nxt.first) continue;
            dist[nxt.second] = dist[cur.second]+nxt.first;
            pq.push({dist[nxt.second],nxt.second});
        }
    }

    return dist[end];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;

    for(int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b}); // 비용 정점
        adj[b].push_back({c,a}); // 양방향 길 존재
    }
    cin >> spot1 >> spot2;

    long long case1 = solve(1,spot1) + solve(spot1,spot2) + solve(spot2,N);    
    long long case2 = solve(1,spot2) + solve(spot2,spot1) + solve(spot1,N);
    
    long long ans = min(case1,case2);
    if(ans >= INF ) cout << -1;
    else cout << ans;
    
    return 0;
}
