#include <bits/stdc++.h>
using namespace std;

// 25.03.08 케빈 베이컨의 6단계 법칙 복습 (그래프) 
int N,M; 
vector<int> adj[105];
int dist[105]; // 거리 계산

int bfs(int node) {
    fill(dist,dist+N+1,-1);
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    int sum = 0; // 수들의 총합

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]) {
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur]+1;
            sum += dist[nxt]; // 총합 누적
            q.push(nxt);
        }
    }
    
    return sum;
}

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
    
    int min_k = INT_MAX; 
    int ans;
    for(int i=1; i<=N; i++) {
        int kevin = bfs(i); // bfs로 케빈 베이컨 수 구하기 
        if(kevin<min_k) { // 가장 작은 케빈 베이컨 수 찾기
            min_k = kevin;
            ans = i; // 가장 번호가 작은 사람
        }
    }

    cout << ans;
    return 0;
}
