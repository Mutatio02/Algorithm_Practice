#include <bits/stdc++.h>
using namespace std;
// 25.2.5 구간 합 구하기 4 (DP 복습) 
int N,M;
int dp[100001]; // 합 저장해 두기
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++) { // 1 based
        cin >> arr[i]; 
        dp[i] = dp[i-1] + arr[i]; // 누적 = 누적이전까지의 합 + 입력값
    }

    while(M--) {
        int x,y;
        cin >> x >> y;
        cout << dp[y] - dp[x-1] << "\n";
    }
    return 0;
}
