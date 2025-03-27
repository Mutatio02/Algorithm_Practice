#include <bits/stdc++.h>
using namespace std;

// 25.03.27 행성 연결(최소 신장 트리) --> 크루스칼
int N;
int p[1005]; // 부모 배열
vector<tuple<long long,int,int>> edge; // 비용과 간선

int find(int x) {
    if(p[x]<0) return x;
    return p[x] = find(p[x]);
}
bool is_group(int u,int v) {
    u = find(u);
    v = find(v);

    if(u==v) return 0;
    if(p[u]==p[v]) p[u]--;
    if(p[u]<p[v]) p[v] = u; // 크기비교에 따라 부모를 연결
    else p[u] = v;
    
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    fill(p,p+N+1,-1);

    long long C;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> C;
            if(i==j) continue;
            edge.push_back({C,i,j});            
        }
    }
    sort(edge.begin(),edge.end()); // 가중치(비용) 별로 정렬

    int cnt = 0; // 탐색 개수
    long long ans = 0;
    for (auto e: edge) {
        long long cost;
        int u,v;
        tie(cost,u,v) = e;
        if(!is_group(u,v)) continue;
        cnt++;
        ans += cost;
        if(cnt== N-1) break; // 총 탐색 간선은 N-1이다
    }
    
    cout << ans;
    return 0;
}
