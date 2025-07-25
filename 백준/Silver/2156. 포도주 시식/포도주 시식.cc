#include <bits/stdc++.h>
using namespace std;
// 25.05.27 포도주 시식
int N;
int arr[10005];
int dp[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    if(N>=2) dp[2] = dp[1] + arr[2];
    for(int i=3; i<=N; i++) {
        dp[i] = max({dp[i-1], 
            dp[i-2] + arr[i],
            dp[i-3] + arr[i-1] + arr[i] 
        });
    } 
    cout << dp[N];

    return 0;
}
