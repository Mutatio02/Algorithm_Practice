#include <bits/stdc++.h>
using namespace std;

// 25.04.04 궁금한 민호 (플로이드 알고리즘)
int N;
int dp[25][25]; // 이미 최소비용으로 주어짐
int origin[25][25];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> dp[i][j];
            origin[i][j] = dp[i][j];
        }
    }
    
    bool isNeed = true; 
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(i==j || i==k || j==k) continue;
                if(dp[i][j]>dp[i][k]+dp[k][j]) { // 이미 플로이드를 만족했지만 또 있다면 문제 발생
                    isNeed = false;
                }
                else if(dp[i][j]==dp[i][k]+dp[k][j]) { 
                    origin[i][j] = origin[j][i] = 0;
                }
            }
        }
    }
    

    if(!isNeed) {
        cout << -1;
        return 0;
    }

    int ans = 0;
    for(int i=1; i<=N; i++) {
        for(int j=i+1; j<=N; j++) {
            ans += origin[i][j];
        }
    }

    cout << ans;

    
    return 0;
}




