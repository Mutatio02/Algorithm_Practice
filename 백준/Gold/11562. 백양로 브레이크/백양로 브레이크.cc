#include <bits/stdc++.h>
using namespace std;

// 25.04.03 백양로 브레이크 (플로이드 알고리즘)
int n,m;
int K;
int dp[255][255];
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        fill(dp[i]+1,dp[i]+n+1,INF);
        dp[i][i] = 0;
    }

    for(int i=0; i<m; i++) {
        int u,v,b;
        cin >> u >> v >> b;
        if(b==0) { // 일방통행
            dp[u][v] = 0;
            dp[v][u] = 1; // 일방통행일떄 돌아오는 경로의 비용은 추가
        }   
        else if(b==1) { // 양방향
            dp[u][v]=0;
            dp[v][u]=0;
        } 
    }
    // 플로이드
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dp[i][j]>dp[i][k]+dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    cin >> K;
    while(K--) {
        int s,e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }


    return 0;

}

