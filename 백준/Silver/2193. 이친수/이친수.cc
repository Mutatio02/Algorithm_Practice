#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long dp[91][2]; // dp[n][0] 은 끝 자리가 0, dp[n][1]은 끝 자리가 1

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i=2; i<=N; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
     }

    cout << dp[N][0] + dp[N][1];

    return 0;
}
