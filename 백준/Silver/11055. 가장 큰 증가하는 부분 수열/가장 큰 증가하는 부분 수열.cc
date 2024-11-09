#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1001];
int arr[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<i; j++) {
            if(arr[i] > arr[j]) { // 증가하는 부분이라면
                dp[i] = max(dp[j]+arr[i],dp[i]); 
            }
        }
    }

    int result = *max_element(dp+1,dp+N+1);
    cout << result;

    return 0;
}
