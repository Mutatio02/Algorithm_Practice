#include <bits/stdc++.h>
using namespace std;

// 25.03.05 바이러스 복습 (그래프) -- 인접 리스트 dfs(재귀)
int N,M;
vector<int> arr[105];
bool vis[105];
int cnt = 0;

void dfs(int node) {
    vis[node] = true;

    for(auto nxt : arr[node]) {
        if(vis[nxt]) continue;
        cnt++;
        dfs(nxt);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> M;
    
    while(M--) {
        int u,v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    for(int i=1; i<=N; i++) {
        sort(arr[i].begin(),arr[i].end());
    }

    dfs(1);
    cout << cnt;
    return 0;
}
