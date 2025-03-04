#include <bits/stdc++.h>
using namespace std;

// 25.03.04 DFS와 BFS 복습 (그래프) -- 인접 리스트
int N,M,V;
vector<int> arr[1005];
bool vis[1005];

void reset() {
    fill(vis,vis+1005,false);
}
void dfs(int node) { // 재귀 dfs
    vis[node] = true;
    cout << node << ' ';
    for(auto nxt : arr[node]) {
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

void dfs2(int node) { // 비 재귀 dfs
    stack<int> stk;
    stk.push(node);
    while(!stk.empty()) {
        int cur = stk.top();
        stk.pop();
        
        if(vis[cur]) continue;
        vis[cur] = true;
        cout << cur << ' ';

        for(int i=0; i<arr[cur].size(); i++) {
            int nxt = arr[cur][arr[cur].size()-1-i];
            if(vis[nxt]) continue;
            stk.push(nxt);
        }
    }
}

void bfs(int node) {
    queue<int> q;
    q.push(node);
    vis[node] = true;
    
    while(!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();

        for(auto nxt : arr[cur]) {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> V;
    while(M--) {
        int u,v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    for(int i=1; i<=N; i++) {
        sort(arr[i].begin(),arr[i].end());
    }

    reset();
    //dfs(V);
    dfs2(V);
    reset();
    cout << "\n";
    bfs(V);

    return 0;
}
