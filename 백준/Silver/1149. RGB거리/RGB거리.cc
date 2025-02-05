#include <bits/stdc++.h>
using namespace std;
// 25.2.5 RGB거리 (DP 복습) 
int N;
int dp[1010][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<3; j++) {
            cin >> dp[i][j];
        }
    }

    for(int i=1; i<=N; i++) {
        dp[i][0] += min(dp[i-1][1],dp[i-1][2]); // Red -> green, blue
        dp[i][1] += min(dp[i-1][0],dp[i-1][2]); // Green -> red, blue
        dp[i][2] += min(dp[i-1][0],dp[i-1][1]); // Blue -> red, green
    }

    int result = min({dp[N-1][0],dp[N-1][1],dp[N-1][2]});

    cout << result;

    return 0;
}
