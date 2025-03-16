#include <bits/stdc++.h>
using namespace std;
// 25.03.16 트리 (트리)
int N,del; 
vector<int> adj[55];
int cnt = 0; // 리프노트 개수
int root = 0; // 루트 노드

void dfs(int node) {
    if(adj[node].empty() || adj[node].size()==1 && adj[node][0] == del) {
        cnt++; // 리프 노드거나 자식이 한명 존재할때 그것이 del일 경우
        return;
    }
    
    for(int nxt : adj[node]) {
        if(nxt!=del) dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for(int i=0; i<N; i++) {
        int node;
        cin >> node; // 부모노드
        if(node!=-1) {
            adj[node].push_back(i);
        }
        else root = i;
    }
    cin >> del;

    if(del == root) {
        cout << 0;
        return 0;
    }

    dfs(root);

    cout << cnt;

    return 0;
}
