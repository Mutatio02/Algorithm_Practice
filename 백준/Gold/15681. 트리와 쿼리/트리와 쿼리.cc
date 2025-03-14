#include <bits/stdc++.h>
using namespace std;
// 25.03.14 트리와 쿼리 (트리)
int N,R,Q;
vector<int> adj[100005];
bool vis[100005];
int subtree[100005]; // 서브트리 정점수 저장

int dfs(int cur) {
    vis[cur] = true;
    subtree[cur] = 1;

    for(int nxt : adj[cur]) {
        if(vis[nxt]) continue; // 방문했던 것은 무시
        subtree[cur] += dfs(nxt); // subtree의 정점수를 계속 더하기
    }

    return subtree[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> Q;
    for(int i=0; i<N-1; i++) {
        int U,V;
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    dfs(R); // R을 root로 하고 dfs를 수행하며

    while(Q--) {
        int u;
        cin >> u;
        cout << subtree[u] << "\n";
    }

    return 0;
}
