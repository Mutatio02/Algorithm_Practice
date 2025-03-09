#include <bits/stdc++.h>
using namespace std;

// 25.03.09 구슬찾기 (그래프) 
int N,M;
vector<int> heavy[105]; // 무거운 것 
vector<int> light[105]; // 가벼운 것
bool vis[105];

int bfs(vector<int> adj[], int start) {
    fill(vis+1,vis+N+1,false);
    queue<int> q;
    q.push(start);
    vis[start]= true;

    int cnt = 0;// 방문한 구슬의 개수 -- 무겁거나 가벼운 구슬들
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]) {
            if(vis[nxt]) continue;
            cnt++;
            vis[nxt] = true;
            q.push(nxt);
        }
    }

    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int u,v;
        cin >> u >> v; // u가 v 보다 무겁다
        heavy[v].push_back(u); // 무거운 것
        light[u].push_back(v); // 가벼운 것
    }

    int mid = (N+1)/2; // 중간
    int ans = 0;

    for(int i=1; i<=N; i++) {
        int h = bfs(heavy,i); // 무거운 것의 개수
        int l = bfs(light,i); // 가벼운 것의 개수

        if(h>=mid || l>=mid) ans++; 
    }
    cout << ans;

    return 0;
}
