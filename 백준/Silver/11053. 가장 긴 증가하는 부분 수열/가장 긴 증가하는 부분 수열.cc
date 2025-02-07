#include <bits/stdc++.h>
using namespace std;
// 25.02.08 가장 긴 증가하는 부분 수열(dp복습)
int N;
int arr[1010];
int dp[1010];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        dp[i] = 1; // 1로 초기화
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<i; j++) {
            if(arr[i] >arr[j]) {
                dp[i] = max(dp[i],dp[j]+1); // rl
            }
        }
    }

    int ans = *max_element(dp+1,dp+N+1);
    cout << ans;

    return 0;
}
