#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int board[1001][1001]; // 인접 행렬
bool visit[1001];      // 방문 여부

// 방문 상태 초기화
void Reset() {
    for (int i = 0; i < 1001; i++) {
        visit[i] = false; 
    }
}

void DFS(int n, int v) {
    visit[v] = true;
    cout << v << ' ';
    for(int i=1; i<=n; i++) {
        if(board[v][i] == 1 && !visit[i]) {
            DFS(n,i);
        }
    }
}

void BFS(int n, int v) {
    queue<int> que;
    que.push(v);
    visit[v] = true;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        cout << cur << ' ';

        for (int i = 1; i <= n; i++) {
            if (board[cur][i] == 1 && !visit[i]) {
                que.push(i);
                visit[i] = true;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, V; // 정점 수, 간선 수, 시작 정점 번호
    cin >> N >> M >> V;

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            board[i][j] = 0; // 초기화
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1; // 양방향 연결
        board[y][x] = 1; 
    }

    Reset();        
    DFS(N, V);      
    cout << '\n';   

    Reset();        
    BFS(N, V);     

    return 0;
}
