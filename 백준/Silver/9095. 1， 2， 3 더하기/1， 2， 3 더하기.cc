#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int dp[12] = {0};

    int T;
    cin >> T;

    dp[1] = 1; // 1
    dp[2] = 2; // (1,1)과 2
    dp[3] = 4; // (1,1,1) (1,2) (2,1) 과 3

    for(int i=4; i<12; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; // 다음 점화식은 4부터 성립
    }

    while(T--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}
