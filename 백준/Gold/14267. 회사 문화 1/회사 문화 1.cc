#include <bits/stdc++.h>
using namespace std;
// 25.05.14 회사 문화1 (graph dp)
int n,m;
vector<int> tree[100005];
int cost[100005];

void dfs(int cur) {
    for(int nxt : tree[cur]) {
        cost[nxt] += cost[cur];
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        int boss;
        cin >> boss;
        if(boss==-1) continue;
        tree[boss].push_back(i);
    }

    while(m--) {
        int i,w;
        cin >> i >> w;
        cost[i] += w;
    }

    dfs(1);
    
    for(int i=1; i<=n; i++) {
        cout << cost[i] << " ";
    }

    return 0;
}
