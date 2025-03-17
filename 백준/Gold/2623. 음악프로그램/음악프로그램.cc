#include <bits/stdc++.h>
using namespace std;
// 25.03.17 음악 프로그램 (위상정렬)
int N,M;
int degree[1005]; // 진입차수 저장
vector<int> adj[1005];

void solve() {
    queue<int> q;
    vector<int> ans;
    for(int i=1; i<=N; i++) {
        if(degree[i]==0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        
        for(int nxt : adj[cur]) {
            degree[nxt]--; // 진입 차수 줄이기
            if(degree[nxt]==0) { // 위상 정렬은 진입차수 0일때
                q.push(nxt);
            }
        }
    }

    if(ans.size()!=N) { // 위상정렬 불가하여 N개가 아님(사이클)
        cout << 0;
        return;
    }

    for(int v : ans) {
        cout << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int singer,prev;
        cin >> singer; // 보조 pd의 가수

        cin >> prev; // 맨 먼저 입력받고

        for(int i=1; i<singer; i++) { // 나머지 입력
            int cur;
            cin >> cur;
            adj[prev].push_back(cur); // 리스트 연결
            degree[cur]++;
            prev = cur; // 인접 리스트 연결을 위해 교환
        }
    }
    solve();

    return 0;
}
