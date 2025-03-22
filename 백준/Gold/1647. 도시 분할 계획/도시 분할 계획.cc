#include <bits/stdc++.h>
using namespace std;

// 25.03.22 도시 분할 계획 (최소 신장 트리) -- 크루스칼
int N,M;
vector<int> p(100005,-1);
tuple<int,int,int> edge[1000005];

int find(int x) {
    if(p[x]<0) return x;
    return p[x] = find(p[x]);
}
bool is_Group(int u,int v) {
    u = find(u); v = find(v);
    if(u==v) return false;
    if(p[u]==p[v]) p[u]--;
    if(p[u]<p[v]) p[v] = u;
    else p[u] = v;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[i] = {c,a,b};
    }
    sort(edge,edge+M); // 오름차순 정렬
    
    int total = 0; // 최소 신장 트리의 총 비용
    int max_edge = 0; // 가장 큰 노드의 가중치 --> 총비용에서 뺀다.(둘로 나누기 위해서)
    int cnt = 0;

    for(int i=0; i<M; i++) {
        int cost,u,v;
        tie(cost,u,v) = edge[i];

        if(is_Group(u,v)) {
            total+=cost;
            max_edge = max(cost,max_edge);
            cnt++;
        }
        if(cnt==N-1) break;
    }

    cout << total - max_edge;
    return 0;
}