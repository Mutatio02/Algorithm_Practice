#include <bits/stdc++.h>
using namespace std;

// 25.03.04 연결요소의 개수 복습 (그래프)-- 인접행렬 방식 + dfs
int N,M;
int arr[1005][1005];
bool vis[1005];

void dfs(int cur) {
    vis[cur] = true;
    
    for(int i=1; i<=N; i++) {
        if(arr[cur][i] == 1 && !vis[i]) {
            dfs(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M;

    while(M--) {
        int u,v;
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
   
    int cnt = 0;    

    for(int i=1; i<=N; i++) {
        if(!vis[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
