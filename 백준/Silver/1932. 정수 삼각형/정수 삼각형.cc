#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[501][501];
int dp[501][501];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N; // 삼각형의 크기

    for(int i = 1; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];

    for(int i=2; i<=N; i++) {
        for(int j=1; j<=i; j++) { // 파스칼의 삼각형 원리
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + arr[i][j];
        }
    }
    int result = *max_element(dp[N]+1,dp[N]+N+1);
    cout << result;
    return 0;
}
