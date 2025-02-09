#include <bits/stdc++.h>
using namespace std;
// 25.02.09 퇴사(dp복습)

int N;
int day[20]; // 상담 소요 기간
int money[20]; // 금액
int dp[20]; // 최대 이익 계산

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1; i<=N; i++) {
        cin >> day[i] >> money[i];
    }
    
    for(int i=1; i<=N; i++) {
        dp[i] = max(dp[i],dp[i-1]); // 현재 저장된 건과 이전값 비교
        
        int next = i + day[i]; // 다음날

        if(next<=N+1) { // 퇴사 전까지
            dp[next]= max(dp[next], dp[i] + money[i]);
        }

    }

    int ans = max(dp[N],dp[N+1]);
    cout << ans;
    
    return 0;
}
