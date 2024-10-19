#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long dp[31][31];
void com(int n,int m) {
    for(int i=0; i<=m; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    cout << dp[m][n] << '\n';
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int N,M;
        cin >> N >> M;
        com(N,M);     
    }

    return 0;
}
