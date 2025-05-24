#include <bits/stdc++.h>
using namespace std;
// 25.05.24 웜홀 (벨만 포드)
int TC;
int dist[505];
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--) {
        vector<tuple<int,int,int>> edges;
        
        int N,M,W;
        cin >> N >> M >> W;
        fill(dist,dist+N+1,INF);

        for(int i=0; i<M; i++) {
            int S,E,T;
            cin >> S >> E >> T;
            edges.push_back({S,E,T});
            edges.push_back({E,S,T});
        }

        for(int j=0; j<W; j++) {
            int S,E,T;
            cin >> S >> E >> T;
            edges.push_back({S,E,-T}); // 되돌아간다.
        }
        
        
        for(int i=0; i<N-1; i++) { // N-1번 실행
            for(auto [from,to,cost]: edges) {
                if(dist[to] > dist[from]+cost) {
                    dist[to] = dist[from]+cost;
                }
            }
        }
        bool isCycle = false;

        for(auto [from,to,cost]: edges) {
            if(dist[to] > dist[from]+cost) {
                dist[to] = dist[from]+cost;
                isCycle = true;
                break;
            }
        }
        cout << (isCycle ? "YES" : "NO") << "\n";

    }

    
    return 0;
}
