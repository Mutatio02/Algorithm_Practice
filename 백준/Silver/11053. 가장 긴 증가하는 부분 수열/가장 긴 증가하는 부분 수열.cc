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

    for(int i=0; i<N; i++) {
        cin >> arr[i];
        dp[i] = 1; // 길이를 1로 초기화
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i],dp[j]+1); // 길이를 1로 늘리기
            }
        }
    }
    int result = *max_element(dp,dp+N);
    cout << result;
     
    return 0;
}
