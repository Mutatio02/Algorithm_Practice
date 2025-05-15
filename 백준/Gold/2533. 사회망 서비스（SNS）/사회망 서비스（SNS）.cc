#include <bits/stdc++.h>
using namespace std;
// 25.05.16  사회망 서비스(SNS)
long long N;
vector<long long> tree[1000005];
long long dp[1000005][2]; // [0] 은 얼리어답터O [1] 은 얼리어답터X
bool vis[1000005];

void dfs(int cur) {
    vis[cur] = true;
    dp[cur][0] = 1;
    
    for(int nxt : tree[cur]) {
        if(vis[nxt]) continue;
        dfs(nxt); // bottom-up 
        dp[cur][0] += min(dp[nxt][0],dp[nxt][1]); // 얼리 어탑터이거나 아니거나
        dp[cur][1] += dp[nxt][0]; // 무조건 얼리어답터
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N-1; i++) {
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    cout << min(dp[1][0],dp[1][1]);
    return 0;
}
