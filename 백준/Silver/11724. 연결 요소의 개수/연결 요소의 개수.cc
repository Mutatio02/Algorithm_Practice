#include <bits/stdc++.h>
using namespace std;

// 25.03.04 연결요소의 개수 복습 (그래프)-- 인접리스트 + bfs
int N,M;
vector<int> arr[1005];
bool vis[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M;

    while(M--) {
        int u,v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
   
    int cnt = 0;    
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        cnt++;
        
        queue<int> q;
        q.push(i);
        vis[i] = true;
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(auto nxt: arr[cur]) {
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    

    cout << cnt;

    return 0;
}
