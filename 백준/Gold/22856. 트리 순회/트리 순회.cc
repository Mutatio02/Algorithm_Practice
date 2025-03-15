#include <bits/stdc++.h>
using namespace std;
// 25.03.15 트리 순회 (트리)
int N;
const int mm = 100005;
int p[mm], lc[mm], rc[mm];
bool vis[mm];
int root = 1;
int cnt = 0; // 횟수
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    p[root] = -1; // 루트 노드
    for(int i=0; i<N; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        lc[a]=b;
        rc[a]=c;
        p[b] = a;
        p[c] = a;
    }
    
    int end = root; // 현재 끝점은 root
    while(rc[end]!=-1) { // 오른쪽 마지막 자식노드
        end = rc[end];
    }
    
    int cur = root;
    while(true) { // 5번 조건
        vis[cur] = true;
        cnt++;
        
        if(lc[cur]!=-1&& !vis[lc[cur]]) { // 1번 조건
            cur = lc[cur];
        }
        else if(rc[cur]!=-1&& !vis[rc[cur]]) { // 2번 조건
            cur = rc[cur];
        }
        else if(cur == end) break; // 3번 조건
        else cur = p[cur]; // 4번 조건
    }
    cout << cnt -1; // 루트 노드 방문 제외
    return 0;
}
