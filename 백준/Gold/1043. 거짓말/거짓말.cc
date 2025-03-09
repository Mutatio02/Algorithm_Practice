#include <bits/stdc++.h>
using namespace std;

// 25.03.09 거짓말 (그래프) 
int N,M,fact;
vector<int> adj[55]; // 인접 리스트
vector<int> party[55]; // 파티 묶기
bool check[55]; // 진실


void bfs() {
    queue<int> q;
    for(int i=1; i<=N; i++) {
        if(check[i]) q.push(i); // 진실을 알면 전파
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int nxt : adj[cur]) {
                if(check[nxt]) continue;
                check[nxt] = true;
                q.push(nxt);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M  >> fact; // 사람 수, 파티 수, 진실 아는 사람수
    while(fact--) {
        int num;
        cin >> num;
        check[num] = true;
    }

    for(int i=0; i<M; i++) {
        int num;
        cin >> num; // 파티에 오는 사람수

        int prev,nxt;// 맨 처음과 그 나머지
        cin >> prev;
        party[i].push_back(prev); // 연결 리스트로 파티 연결

        while(--num) {// 파티에 오는 사람수에서 1명을 감소시켜 입력
            cin >> nxt;
            adj[prev].push_back(nxt);
            adj[nxt].push_back(prev);
            swap(prev,nxt); // 연결 리스트 연결을 위해 nxt를 prv로 설정
        }

    }

    bfs(); // 진실 전파

    int ans = 0; // 거짓말 할 수 있는 파티수
    for(int i=0; i<M; i++) { 
        bool liar = false; 
        for(int tr : party[i]) {
            if(check[tr]) liar = true;
        }
        if(!liar) ans++;
    }

    cout << ans;

    return 0;
}
