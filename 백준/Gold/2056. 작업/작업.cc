#include <bits/stdc++.h>
using namespace std;
// 25.03.19 작업 (위상정렬)
int N;
int wt[10005]; // 작업 소요 시간 저장
int degree[10005]; // 각 작업의 진입 차수
vector<int> adj[10005]; // 그래프
int ans[10005]; // i번쨰 작업에 걸리는 최소 시간

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) {
        int t,w; // 작업에 걸리는 시간, 선행 관계 작업수
        cin >> t >> w;
        wt[i] = t;
        ans[i] = t; // 최소한 걸리는 시간

        while(w--) {
            int x;
            cin >> x;
            degree[i]++; // x가 먼저 선행 되어 i번 작업을 수행 가능
            adj[x].push_back(i); // 그래프 연결
        }
    }

    queue<int> q;
    for(int i=1; i<=N; i++) {
        if(degree[i]==0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt: adj[cur]) {
            ans[nxt] = max(ans[nxt],wt[nxt]+ans[cur]); // 이전작업시간(ans[cur]) 현재 다음작업시간(wt[nxt]) 
            degree[nxt]--; // 진입차수 감소
            if(degree[nxt]==0) {
                q.push(nxt);
            }
        }
    }

    cout << *max_element(ans+1,ans+N+1);

    return 0;
}
