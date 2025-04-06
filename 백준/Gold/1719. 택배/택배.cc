#include <bits/stdc++.h>
using namespace std;

// 25.04.07 택배 (플로이드 알고리즘)
int n,m;
int dp[205][205];
int nxt[205][205];
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        fill(dp[i]+1,dp[i]+n+1,INF);
        dp[i][i] = 0;
    }

    while(m--) {
        int u,v,cost;
        cin >> u >> v >> cost;
        dp[u][v] = cost;
        dp[v][u] = cost;
        nxt[u][v] = v; // u->v의 경로는 v로 간다는 표시
        nxt[v][u] = u; // 반대는 u로 간다는 표시
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dp[i][j]>dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) cout << '-' << ' ';
            else cout << nxt[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}




