#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1000001]; // 계산 횟수 dp
int arr[1000001]; // 계산 하기 이전의 수 저장

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    dp[1] = 0;

    for(int i=2 ; i<=N; i++) {
        dp[i] = dp[i-1] + 1; // 1로 뺴기
        arr[i] = i-1;

        if(i%2 ==0 && dp[i] > dp[i/2] +1 ) {
            dp[i] = dp[i/2] + 1; // 2로 나누기
            arr[i] = i/2;
        }
        
        if(i%3 == 0  && dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] +1; // 3로 나누기
            arr[i] = i/3;
        }
    }
    
    cout << dp[N] << '\n';
    int cur = N;
    while(cur >0) {
        cout << cur << ' ';
        cur = arr[cur];
    }
    return 0;
}
