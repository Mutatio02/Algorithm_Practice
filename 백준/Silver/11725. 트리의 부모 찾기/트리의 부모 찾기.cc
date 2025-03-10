#include <bits/stdc++.h>
using namespace std;

// 25.03.10 트리의 부포찾기 (트리) 
int N;
vector<int> adj[100005];
int p[100005];

void dfs(int cur) { // 1 -> 4(2,7), 6(3)/ 3(5)
    for(int nxt : adj[cur]) {
        if(p[cur] == nxt) continue; // 부모면 무시해라
        p[nxt] = cur; // 부모로 저징
        dfs(nxt);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N-1; i++) {
        int u,v;
        cin >> u >> v; // 노드들을 연결
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    p[1] = 1;
    dfs(1);
    
    for(int i=2; i<=N; i++) {
        cout << p[i] << "\n"; 
    }
    return 0;
}
