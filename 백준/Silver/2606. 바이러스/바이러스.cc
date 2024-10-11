#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int board[101][101]; // 연결된 것 표시
int visit[101]; // 방문 표시

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T; // 컴퓨터 수
    int N;
    cin >> N; // 연결되어 있는 쌍의 수
    queue<int> que;
    for(int i=0; i<N; i++) {
        int x,y;
        cin >> x >> y; // 서로 연결
        board[x][y] = 1; 
        board[y][x] = 1;
    }
    visit[1] = 1; // 바이러스 방문
    que.push(1);
    int cnt =0;
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();

        for(int i=1; i<=T; i++) {
            if(board[cur][i] == 1 && visit[i] !=1 ) { // 연결되었지만 방문 안한 경우
                que.push(i);
                visit[i] = 1; // 방문했다고 표시
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
