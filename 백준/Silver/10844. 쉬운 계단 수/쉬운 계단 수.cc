#include <bits/stdc++.h>
using namespace std;
// 25.02.08 쉬운 계단수(dp복습)

int N;
long long dp[101][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for(int i=1; i<10; i++) {
        dp[1][i]=1;
    }

    for(int i=2; i<=N; i++) {
        for(int j=0; j<10; j++) {
            if(j-1 >=0) {
                dp[i][j] += dp[i-1][j-1];
            }
            if(j+1<=9) {
                dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j] %= 1000000000;
        }
    }

    long long ans = 0;
    for(int i=0; i<10; i++) {
        ans += dp[N][i];
        ans %= 1000000000;
    }
    
    cout << ans;

    return 0;
}
