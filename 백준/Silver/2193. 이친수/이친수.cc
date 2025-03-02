#include <bits/stdc++.h>
using namespace std;
// 25.02.07 이친수(dp복습)
int n;
long long dp[91][2]; // n자리 자연수 끝이 0 또는 1

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i][0] = dp[i-1][0] +dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[n][0] + dp[n][1];
    
}
