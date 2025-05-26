#include <bits/stdc++.h>
using namespace std;
// 25.05.26 오르막 수 (다이나믹 프로그래밍)
int N;
const int MOD = 10007;
int dp[1005][1000]; // 길이가 i이고 마지막 수가 j 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for(int j=0; j<=9; j++) {
        dp[1][j] = 1; // 길이가 1인 것중에서 숫자들은 모두 다 1개
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=9; j++) {
            for(int k=0; k<=j; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int j=0; j<=9; j++) {
        ans = (ans + dp[N][j]) % MOD;
    }
    cout << ans;

    return 0;

}
