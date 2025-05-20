#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<tuple<int, int, int>> edges;
long long dist[505];
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    fill(dist, dist + N + 1, INF);

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({A, B, C});
    }

    dist[1] = 0;

    // N-1번 반복
    for (int i = 0; i < N - 1; i++) {
        for (auto [from, to, cost] : edges) {
            if (dist[from] != INF && dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
            }
        }
    }

    // 음수 사이클 1회 검사
    for (auto [from, to, cost] : edges) {
        if (dist[from] != INF && dist[to] > dist[from] + cost) {
            cout << -1 << "\n";
            return 0;
        }
    }

    // 거리 출력
    for (int i = 2; i <= N; i++) {
        if (dist[i] == INF)
            cout << -1 << "\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
