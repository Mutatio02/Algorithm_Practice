#include <bits/stdc++.h>
using namespace std;
// 25.03.16 줄세우기 (위상정렬)
int N,M;
vector<int> adj[32005];
int degree[32005]; // 전입차수
vector<int> ans;

void solve() {
    queue<int> q;
    for(int i=1; i<=N; i++) {
        if(degree[i]==0) q.push(i); // 위상정렬은 전입차수가 
        // 0인 것부터 시작
    }    
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(int nxt: adj[cur]) {
            degree[nxt]--;
            if(degree[nxt]==0) {
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        degree[b]++; // 전입차수 증가
    }

    solve();
    
    for(int v : ans) {
        cout << v << " ";
    }
    return 0;
}
