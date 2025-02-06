#include <bits/stdc++.h>
using namespace std;
// 25.02.06 정수 삼각형(dp복습)
int n;
int dp[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + 2*(dp[i-2]);
        dp[i]%=10007;
    }
    
    cout << dp[n];
}
