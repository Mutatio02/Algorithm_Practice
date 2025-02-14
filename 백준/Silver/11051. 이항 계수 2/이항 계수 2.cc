#include <bits/stdc++.h>
using namespace std;

// 25.02.14 이항계수2 (수학) 
long long N,K;
long long dp[1010][1010];
int mod = 10007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    
    for(int i=0; i<=N; i++) {
        for(int j=0; j<=i; j++) {
            if(j==0 || j==i) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod; 
            }
        }
    }
    
    cout << dp[N][K];

    return 0;
}
