#include <bits/stdc++.h>
using namespace std;
// 25.05.10 피보나치 수2  (다이나믹 프로그래밍)
long long N;
long long dp[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;    
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << dp[N-1];

    return 0;
}
