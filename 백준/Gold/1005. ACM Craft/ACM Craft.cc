#include <bits/stdc++.h>
using namespace std;
// 25.03.17 ACM Craft (위상정렬)
int T;
int N,K,W;
int build[1005]; // 건설 시간
int degree[1005]; // 진입 차수
int ans[1005]; // 건물 완성 시간
vector<int> adj[1005]; // 그래프

void reset() {
    fill(build,build+N+1,0);
    fill(degree,degree+N+1,0);
    fill(ans,ans+N+1,0);

    for(int i=1; i<=N; i++) {
        adj[i].clear();
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> N >> K;
        queue<int> q;

        reset();

        for(int i=1; i<=N; i++) {
            cin >> build[i];
        }
        while(K--) {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v); // 그래프연결
            degree[v]++; // 진입차수 증가
        }
        cin >> W;

        for(int i=1; i<=N; i++) {
            if(degree[i]==0) q.push(i);
            ans[i] = build[i];
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            

            for(int nxt : adj[cur]) {
                ans[nxt] = max(ans[nxt],ans[cur]+build[nxt]); // 다음 건설 시간
                degree[nxt]--;
                
                if(degree[nxt]==0) {
                    q.push(nxt);
                }
            }
        }
        cout << ans[W] << "\n";
    }
    
    return 0;
}
