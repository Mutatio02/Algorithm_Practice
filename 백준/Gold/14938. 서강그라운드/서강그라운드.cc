#include <bits/stdc++.h>
using namespace std;

// 25.03.29 서강그라운드 (플로이드 알고리즘)
int n,m,r;
int dp[105][105]; // idx는 지역 번호
int item[35];
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r;

    for(int i=1; i<=n; i++) {
        cin >> item[i];
    }

    for(int i=1; i<=n; i++) {
        fill(dp[i],dp[i]+n+1,INF);
        dp[i][i] = 0;
    }

    for(int i=0; i<r; i++) {
        int a,b,l;
        cin >> a >> b >> l;
        dp[a][b] = l;
        dp[b][a] = l;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dp[i][j]> dp[i][k]+dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
        int tmp = 0;
        for(int j=1; j<=n; j++) {
            if(dp[i][j]<=m) {
                tmp += item[j];
            }
        }
        ans = max(ans,tmp);
    }
    
    cout << ans;
}




