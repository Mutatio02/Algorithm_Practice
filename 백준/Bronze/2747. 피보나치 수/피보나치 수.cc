#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[101];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N; 
    
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N];
    
    return 0;
}
