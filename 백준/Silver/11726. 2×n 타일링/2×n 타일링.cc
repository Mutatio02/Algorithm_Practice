#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MOD 10007

using namespace std;
int dp[1001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] = dp[i] % MOD;
    }

    cout << dp[N];
    
    return 0;
}
