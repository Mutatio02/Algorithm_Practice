#include <bits/stdc++.h>
using namespace std;

// 25.04.02 운동 (플로이드)
int V,E;
int dp[405][405];
const int INF = 1e9;
vector<int> combi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for(int i=1; i<=V; i++) {
        fill(dp[i]+1,dp[i]+V+1,INF);
        dp[i][i] = 0;
    }
    
    for(int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        dp[a][b] = c;
    }
    
    // 플로이드
    for(int k=1; k<=V; k++) {
        for(int i=1; i<=V; i++) {
            for(int j=1; j<=V; j++) {
                if(dp[i][j]>dp[i][k]+dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    // 최소 사이클 찾기
    int ans = INF;
    for(int i=1; i<=V; i++) {
        for(int j=i+1; j<=V; j++) {
            ans = min(ans,dp[i][j]+dp[j][i]);
        }
    }

    if(ans == INF) cout << -1;
    else cout << ans;
    
    return 0;

}

