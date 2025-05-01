#include <bits/stdc++.h>
using namespace std;
// 25.05.01 골목 대장 호석 - 효율성 2 (다익스트라)
int N,M,A,B;
typedef long long ll;
ll C;
const int NMX = 100005;
const int MMX = 500005;
vector<pair<ll,int>> adj[MMX]; // 비용과 정점
ll dist[NMX];
const long long INF = 1e18;
ll low = 1, high; // 이분 탐색 진행 변수

bool dijkstra(ll target) {
    fill(dist,dist+N+1,INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    dist[A] = 0;
    pq.push({dist[A],A});
    
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        if(dist[cur.second]!=cur.first) continue;
        for(auto nxt : adj[cur.second]) {
            if(nxt.first>target) continue; // mid 보다 클 경우 무시한다
            if(dist[nxt.second]>dist[cur.second]+nxt.first) {
                dist[nxt.second] =dist[cur.second]+nxt.first;
                pq.push({dist[nxt.second],nxt.second});
            }
        }
    }
    
    return dist[B] <=C;
}   
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> A >> B >> C;

    while(M--) {
        int u,v; ll c;
        cin >> u >> v >> c;
        adj[u].push_back({c,v});
        adj[v].push_back({c,u});
        high = max(high,c); // 상한선
    }

    ll ans = -1;
    while(low<=high) { // 이분탐색으로 비용을 제한하고 
        ll mid = (low + high) / 2;
        if(dijkstra(mid)) { // 재한된 비용 내에서 다익스트라를 통해 비용이 C이하인 지 탐색
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans;
    
    return 0;
}
