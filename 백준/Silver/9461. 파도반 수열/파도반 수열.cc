#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long dp[101];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i< 101; i++) {
        dp[i] = dp[i-2] + dp[i-3];
    }

    while(T--) {
        int N;
        cin >> N;
        
        cout << dp[N]<< '\n';
    }
    
    return 0;
}
