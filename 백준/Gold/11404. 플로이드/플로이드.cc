#include <bits/stdc++.h>
using namespace std;

// 25.03.28 플로이드 (플로이드 알고리즘)
int N,M;
int dp[105][105];
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> M;
    for(int i=1; i<=N; i++) {
        fill(dp[i],dp[i]+N+1,INF);
    }

    int a,b,c;
    while(M--) {
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b],c);
    }

    for(int i=1; i<=N; i++) {
        dp[i][i] = 0; // i==j는 자기 자신
    }

    // 플로이드 워샬
    for(int k=1; k<=N; k++) { // 지나가는 정점
        for(int i=1; i<=N; i++) { // 행
            for(int j=1; j<=N; j++) { // 열
                dp[i][j] = min(dp[i][k]+dp[k][j],dp[i][j]);
            }
        }
    }
    

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(dp[i][j]==INF) cout << 0 << ' ';
            else cout << dp[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}
