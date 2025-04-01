#include <bits/stdc++.h>
using namespace std;

// 25.04.01 우주 탐사선 (플로이드 알고리즘)
int N,K;
const int INF = 1e9;
int dp[15][15];
vector<int> combi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        if(i!=K) combi.push_back(i);
    } // next_permutation을 위한 경우의 수


    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> dp[i][j];
            if(i==j) dp[i][j] = 0;
        }
    }

    for(int k=0; k<N; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k]+dp[k][j];
                }
            }
        }
    }
    
    int ans = INF; // 순열 기반 완전 탐색
    do {
        int tmp = dp[K][combi[0]]; // 맨 처음 위치
        for(int i=1; i<N-1; i++) {
            tmp += dp[combi[i-1]][combi[i]];
        }
        ans = min(tmp,ans);
    }while(next_permutation(combi.begin(),combi.end()));

    cout << ans;

    return 0;

}

