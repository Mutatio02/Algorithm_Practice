#include <bits/stdc++.h>
using namespace std;
// 2025.03.21 물대기(최소 신장 트리) -- 크루스칼 알고리즘 
int N;
int w[305];
vector<int> p(305,-1); // 정점
tuple<int,int,int> edge[100005]; // 간선 (비용,정점1,정점2)
int v,e;

int find(int x) {
    if(p[x]<0) return x;
    return p[x] = find(p[x]);
}
bool union_find(int u,int v) {
    u = find(u); v = find(v);
    if(u==v) return false; // 같은 부모
    if(p[u]==p[v]) p[u]--; // rank가 같으면 u의 rank 증가
    if(p[u]<p[v]) p[v] = u; // u가 더 크다면 v를 u의 자식으로
    else p[u] = v; // 아닐경우 반대로
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v;
    for(int i=1; i<=v; i++) {
        int cost;
        cin >> cost;
        edge[e++] = {cost,i,v+1}; // 가상의 정점을 추가해 가중치를 주는 방식이다.
    }
    
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            int cost;
            cin >> cost;
            if(i>=j) continue; // 중복 저장 무시
            edge[e++] = {cost,i,j};
        }
    }
    v++; // 가상의 정점포함 +1증가
    sort(edge,edge+e);

    int ans = 0;
    int cnt = 0; // 간선 개수 세기

    for(int i=0; i<e; i++) { // 전체 간선 탐색
        int cost,a,b;
        tie(cost,a,b) = edge[i];
        if(!union_find(a,b)) continue; // 같은 부모를 가질경우 무시한다.
        ans += cost;
        cnt++;
        if(cnt==v) break; // 정점-1인 v-1까지 탐색을 마치면 종료
    }

    cout << ans;
    
}
