#include <bits/stdc++.h>
using namespace std;
// 25.03.14 트리 (트리)

int N, M;
vector<int> adj[505];
bool vis[505];

bool dfs(int cur, int prev) {
    vis[cur] = true;
    for(int nxt : adj[cur]) {
        if(nxt == prev) continue; // 부모인 경우 넘어가기
        if(vis[nxt]) return false; // 이미 방문
        if(!dfs(nxt,cur)) return false; // 만약 dfs(nxt,cur) 가
        // 사이클이 존재 하는 경우 false
    }
    return true;
}

void solve(int seq) {
    int cnt = 0; // 트리 개수
    for(int i=1; i<=N; i++){ // 정점은 1부터 N까지
        if(!vis[i]) {
            if(dfs(i,-1)) cnt++;       
        }
    }
    cout << "Case " << seq << ": ";
    if(cnt==0) cout << "No trees. \n";
    else if(cnt==1) cout << "There is one tree.\n";
    else cout << "A forest of " << cnt << " trees.\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testcase = 0;

    while(true) {
        cin >> N >> M;
        if(N==0&& M==0) break;

        for(int i=0; i<=N; i++) { // 초기화
            adj[i].clear();
        }
        fill(vis,vis+N+1,false); // 초기화

        while(M--) {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(++testcase);        
    }
    

    return 0;
}
