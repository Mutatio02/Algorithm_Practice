#include <bits/stdc++.h>
using namespace std;
// 2025.03.20 최소 스패닝 트리(최소 신장 트리) -- 크루스칼 알고리즘 
int V,E;
tuple<int,int,int> edge[100005];
vector<int> p(10005,-1);
int find(int x) {
    if(p[x]<0) return x; // 루트를 찾으면 리턴
    return p[x] = find(p[x]); // 경로 압축
}
bool union_find(int u,int v) {
    u = find(u); v = find(v); // 각자 찾기
    if(u==v) return false; // 같은 집합이다
    if(p[u] == p[v]) p[u]--; // 높이가 같다면 u 높이 증가 (-1로 초기화)
    if(p[u] < p[v]) p[v] = u; // u의 rank가 높다면 v를 u의 자식으로
    else p[u] = v; // 아니면 반대로

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V >> E;
    for(int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c; // 정점 a,b 가중치 c
        edge[i] = {c,a,b}; 
    }
    sort(edge,edge+E); // 가중치를 기준으로 정렬

    int ans = 0;
    int cnt = 0; // 간선개수 세기
    for(int i=0; i<E; i++) {
        int cost,a,b;
        tie(cost,a,b) = edge[i]; 

        if(!union_find(a,b)) continue;
        ans += cost;
        cnt++;
        if(cnt==V-1) break; // MST는 간선의 개수가 V-1개 --> 전부 탐색이므로 종료
    }
    cout << ans;
}
