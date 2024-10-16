#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int dp[50001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++) {
        dp[i] = i; // 최악의 경우의 수
        for(int j =1; j*j<=i; j++) {
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    cout << dp[N];

    return 0;
}
