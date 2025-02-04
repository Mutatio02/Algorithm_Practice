#include <bits/stdc++.h>
using namespace std;
// 25.2.4 1,2,3 더하기(DP 복습) 
int N;
int dp[15];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    // 1,2,3을 이용해 만들 수 있는 경우
    dp[1] = 1; // (1)
    dp[2] = 2; // (1,1) , (2)
    dp[3] = 4; // (1,1,1) , (1,2) , (2,1) , (3)

    for(int i=4; i<15; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    while(N--) {
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }
    return 0;
}
