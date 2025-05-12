#include <bits/stdc++.h>
using namespace std;
// 25.05.12 색상환 (다이나믹 프로그래밍)
int N,K;
const long long mod =  1000000003;
long long dp[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> K;
    for(int i=0; i<=N; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for(int i=2; i<=N; i++) {
        for(int j=2; j<=K; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-2][j-1]; // 마지막 택하지 않을때-> 이전 i-1개에서 j개를 모두 선택
        // 마지막 택할때 인접하지 않게 i-2로 줄이고 j-1로 마지막을 선택한 경우 제거 
            dp[i][j] %= mod;
        }
    }

    cout << (dp[N-1][K] + dp[N-3][K-1]) % mod;

    return 0;
}
