#include <bits/stdc++.h>
using namespace std;

// 25.03.31 가운데에서 만나기 (플로이드 알고리즘)
int N,M;
int K;
int dp[205][205];
const int INF = 1e9;
int live[205]; // 살고 있는 도시들

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        fill(dp[i], dp[i]+N+1,INF);
        dp[i][i] = 0;
    }

    for(int i=0; i<M; i++) {
        int a,b,t;
        cin >> a >> b >> t;
        dp[a][b] = t;
    }
    
    cin >> K;
    for(int i=1; i<=K; i++) {
        cin >> live[i];
    }

    // 플로이드- 와샬
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(dp[i][j]> dp[i][k]+dp[k][j]) {
                    dp[i][j] = dp[i][k]+dp[k][j];
                }
            }
        }
    }

    vector<pair<int,int>> v; // 왕복시간과 정점

    // 최대 왕복 시간 계산
    for(int i=1; i<=N; i++) {
        int mx = 0;
        for(int j=1; j<=K; j++) {
            mx = max(mx,dp[i][live[j]]+dp[live[j]][i]);
        }
        v.push_back({mx,i}); // 왕복시간, 도시 번호
    }

    sort(v.begin(),v.end());

    int limit = v[0].first;

    for(auto ans : v) {
        if(limit < ans.first) break;
        cout << ans.second << ' ';
    }

    
}




