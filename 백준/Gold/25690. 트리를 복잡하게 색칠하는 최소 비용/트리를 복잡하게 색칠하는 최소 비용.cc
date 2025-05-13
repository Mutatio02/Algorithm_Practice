#include <bits/stdc++.h>
using namespace std;
// 25.05.13 트리를 복잡하게 색칠하는 최소 비용 (DP, Graph)
int n;
vector<int> tree[100005];
bool vis[100005];
long long dp[100005][2]; // [0]은 white [1]은 black
long long cost[100005][2];

void dfs(int cur) {
    vis[cur] = true;
    dp[cur][0] = cost[cur][0];
    dp[cur][1] = cost[cur][1];

    for(int nxt : tree[cur]) {
        if(vis[nxt]) continue;
        dfs(nxt);
        dp[cur][0] += min(dp[nxt][0],dp[nxt][1]);
        dp[cur][1] += dp[nxt][0];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    for(int j=0; j<n; j++) {
        cin >> cost[j][0] >> cost[j][1];
    }

    dfs(0);

    cout << min(dp[0][0],dp[0][1]);
    return 0;
}
