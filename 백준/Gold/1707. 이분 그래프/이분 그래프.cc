#include <bits/stdc++.h>
using namespace std;

// 25.03.08 이분 그래프 (그래프) 
int T;
int v,e;
vector<int> adj[20005];
int check[20005]; 

bool isBipertite() { // 인접한 정점들을 구별한다(-1,1)
    fill(check+1,check+v+1,0); // 초기화 --- 아직 방문하지 않은 것은 0으로
    queue<int> q;
    for(int i=1; i<=v; i++) {
        if(check[i]!=0) continue; // 이미 방문 한 것은 무시한다
        q.push(i);
        check[i] = 1; // 맨 처음 1로 표시
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int nxt : adj[cur]) {
                if(check[nxt] == 0) { // 인접한 것은 1과 다른 -1로 구분
                    check[nxt] = -check[cur];
                    q.push(nxt);
                }
                else if(check[nxt]==check[cur]) { // 표시가 같다면 이분 그래프가 아니다
                    return false;
                }
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> v >> e;
        for(int i=1; i<=v; i++) { // 초기화
            adj[i].clear();
        }

        while(e--) {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(isBipertite()) {
            cout << "YES" << "\n";
        }        
        else cout << "NO" << "\n";
    }  
    return 0;
}
