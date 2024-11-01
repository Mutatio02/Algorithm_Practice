#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int result= 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<3; j++) {
            cin >> dp[i][j];
        }
    }

    for(int i=1; i<=N; i++) { // (R이아니면 G,B) (G가아니면 R,B) (B가 아니면 R,G)
        dp[i][0] += min(dp[i-1][1],dp[i-1][2]);// R
        dp[i][1] += min(dp[i-1][0],dp[i-1][2]);// G
        dp[i][2] += min(dp[i-1][0],dp[i-1][1]);// B
    }

    result = min({dp[N-1][0],dp[N-1][1],dp[N-1][2]});
    cout << result;
    return 0;
}
