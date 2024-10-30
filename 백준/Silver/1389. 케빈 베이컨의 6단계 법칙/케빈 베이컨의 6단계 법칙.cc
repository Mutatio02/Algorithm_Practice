#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int board[101][101];
bool visit[101];

int BFS(int start,int N) {
    fill(visit,visit+N+1,false);
    queue<pair<int,int>> que; // 시작 노드 밑 거리
    que.push({start,0});
    visit[start] = true;
    int distance = 0;
    while(!que.empty()) {
        int cur = que.front().first;
        int d = que.front().second;
        que.pop();

        distance += d; // 거리 합산
        for(int i=1; i<=N; i++) {
            if(board[cur][i] == 1 && visit[i] == false) {
                que.push({i,d+1});
                visit[i] = true;
            }
        }
    }
    return distance; // start별로 각 케빈 베이컨의 수 결과 리턴
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M; // 유저 수 친구 관계 수
    cin >> N >> M;
    vector<int> kevin(N+1,0); // 케빈 베이컨의 수 저장
    for(int i=0; i<M; i++) {
        int A,B;
        cin >> A >> B;
        board[A][B] = 1;
        board[B][A] = 1;
    }
    
    for(int i=1; i<=N; i++) {
        kevin[i] = BFS(i,N); // 전체 BFS 탐색
    }
    // 1부터 시작하므로 0에서 1만큼 더해줌
    int result = min_element(kevin.begin()+1,kevin.end()) - kevin.begin();

    cout << result;
    
    return 0;
}
