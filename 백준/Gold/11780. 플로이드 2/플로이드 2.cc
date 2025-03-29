#include <bits/stdc++.h>
using namespace std;

// 25.03.29 플로이드2 (플로이드 알고리즘)
int N,M;
int dp[105][105];
int nxt[105][105]; // 어느 정점의 번호로 가는 것이 적절한가?
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> M;
    for(int i=1; i<=N; i++) {
        fill(dp[i],dp[i]+N+1,INF);
    }

    int a,b,c;
    while(M--) {
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b],c);
        nxt[a][b] = b; // 기본적으로 a에서 b를 방문하는 정점은 b이다. 
    }

    for(int i=1; i<=N; i++) {
        dp[i][i] = 0; // i==j는 자기 자신
    }

    // 플로이드 워샬
    for(int k=1; k<=N; k++) { // 지나가는 정점
        for(int i=1; i<=N; i++) { // 행
            for(int j=1; j<=N; j++) { // 열
                if(dp[i][j] > dp[i][k] + dp[k][j]) { // 더 적은 경로 발견시(정점을 거치는 것이 더 적은 비용)
                    dp[i][j] = dp[i][k] + dp[k][j]; // 더 작은 비용으로 갱신
                    nxt[i][j] = nxt[i][k]; // 더 작은 비용을 찾은 노드로 갱신 i->j 에서 i->k로
                }
                 
            }
        }
    }
    

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(dp[i][j]==INF) cout << 0 << ' ';
            else cout << dp[i][j] << ' ';
        }
        cout << "\n";
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(dp[i][j]==0 || dp[i][j] == INF)  {
                cout << "0\n";
                continue;
            }
            vector<int> v;
            int start = i; // 처음 시작 정점의 번호
            while(start !=j) {
                v.push_back(start);
                start = nxt[start][j]; // 다음 경로 번호
            }
            v.push_back(j);
            cout << v.size() << "\n";
            for(auto p : v) cout << p << " ";
            cout << "\n";
        }
        
    }
    return 0;
}
