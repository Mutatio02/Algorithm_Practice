#include <bits/stdc++.h>
using namespace std;

// 25.03.07 회장뽑기 (그래프) 
int N;
vector<int> adj[55];
vector<int> member; // 회장이 될 수 있는 경우
int score[55]; // 각 정점에서의 점수

int bfs(int node) { // 각 정점에서의 최대 점수 탐색
    queue<int> q;
    int dist[55];
    fill(dist+1,dist+N+1,-1);

    q.push(node);
    dist[node] = 0;
    int point = 0; // 점수

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]) {
            if(dist[nxt]!=-1) continue;
            dist[nxt] = dist[cur]+1;
            point = max(point,dist[nxt]);
            q.push(nxt);
        }
    }

    return point;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(true) {
        int u,v;
        cin >> u >> v;
        if(u==-1 && v==-1) break; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1; i<=N; i++) {
        score[i] = bfs(i);
    }
    
    int minscore = *min_element(score+1,score+N+1);

    for(int i=1; i<=N; i++) {
        if(score[i] == minscore) { // 회장이 될 수 있는  최소 점수면
            member.push_back(i); // 삽입
        }
    }
    cout << minscore << ' ' << member.size() << "\n";
    for(int p : member) {
        cout << p << ' ';
    }
    
    return 0;
}
