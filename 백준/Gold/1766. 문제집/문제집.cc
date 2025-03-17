#include <bits/stdc++.h>
using namespace std;
// 25.03.17 문제집 (위상정렬)
int N,M;
vector<int> adj[32005];
int degree[32005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int a,b;
        cin >> a >> b; // a번 문제가 먼저 푸는 것이 좋다
        adj[a].push_back(b);
        degree[b]++; // b번의 진입차수 늘리기
    }

    priority_queue<int,vector<int>,greater<int>> pq; // 작은 값 부터 출력 위함
    for(int i=1; i<=N; i++) {
        if(degree[i]==0) pq.push(i);
    }

    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";

        for(int nxt : adj[cur]) {
            degree[nxt]--;
            if(degree[nxt]==0) {
                pq.push(nxt);
            }
        }
    }

    return 0;
}
