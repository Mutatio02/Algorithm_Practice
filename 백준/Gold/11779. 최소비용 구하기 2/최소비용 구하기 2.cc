#include <bits/stdc++.h>
using namespace std;

// 25.04.15 최소비용 구하기2 (다익스트라)
int n,m;
int st,ed;
vector<pair<int,int>> adj[1005];
const int INF = 1e9;
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dist[1005]; // 최소 거리
int parent[1005]; // 이전에 방문한 부모 노드

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;
    fill(dist,dist+n+1,INF);
    fill(parent,parent+n+1,-1);

    for(int i=0; i<m; i++) {
        int u,v,w;
        cin >> u >> v >> w; // 출발지 도착지 비용
        adj[u].push_back({w,v}); // 비용(거리) 도착지
    }

    cin >> st >> ed;
    dist[st] = 0; // 시작점 거리는 0
    pq.push({dist[st],st}); // 거리, 시작점

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(dist[cur.second] != cur.first) continue;
        for(auto nxt : adj[cur.second]) {
            if(dist[nxt.second]<=dist[cur.second]+nxt.first) continue; // 더 크면 무시
            dist[nxt.second] = dist[cur.second] + nxt.first; // 아니면 갱신
            pq.push({dist[nxt.second],nxt.second}); // 거리 다음 방문 노드
            parent[nxt.second] = cur.second; // 방문했던 노드 기록
        }
    }

    cout << dist[ed] << "\n";
    vector<int> path;
    int cur = ed;
    while(cur!=st) { // 뒤에서 부터 앞으로 삽입
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(cur); // 첫번째 또한 삽입

    cout << path.size() << "\n";
    reverse(path.begin(),path.end());
    
    for(auto v: path) cout << v << " ";

    return 0;
}
