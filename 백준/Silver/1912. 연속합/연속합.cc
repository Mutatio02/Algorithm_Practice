#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1000001];
int arr[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];

    for(int i=2; i<=N; i++) {
        dp[i] = max(dp[i-1] + arr[i],arr[i]);
    }
    
    int result = *max_element(dp+1,dp+N+1);
    cout << result;

    return 0;
}
