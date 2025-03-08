#include <bits/stdc++.h>
using namespace std;

// 25.03.08 숨바꼭질 (그래프) 
int N,M;
vector<int> adj[20005];
int dist[20005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(dist+1,dist+N+1,-1);
    
    queue<int> q;
    q.push(1); // 1번 헛간 부터 찾는다
    dist[1] = 0;

    int maxdist = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur] ) {
            if(dist[nxt] !=-1) continue;
            dist[nxt] = dist[cur]+1;
            maxdist = max(maxdist,dist[nxt]); // 최대한 멀리 있는 값을 찾는다
            q.push(nxt);
        }
    }

    int cnt = 0; // 같은 거리의 헛간의 수
    int room = 0; // 헛간
    for(int i=1; i<=N; i++) {
        if(dist[i] == maxdist)  {
            if(room==0) room = i;
            cnt++;
        }
    }

    cout << room << ' ' << maxdist  << ' ' << cnt;
    
    return 0;
}
