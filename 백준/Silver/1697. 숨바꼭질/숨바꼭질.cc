#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int board[100001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(board,board+100001,-1); // -1로 전체 초기화

    int N,K;
    cin >> N >> K;
    queue<int> que;
    board[N] = 0; // N 지점은 수빈의 시작위치
    que.push(N);

    while(board[K] == -1) { // 동생의 위치에 갈때까지
        auto cur = que.front();
        que.pop();
        
        for(int dir : {cur-1,cur+1,cur*2}) {
            if(dir<0 || dir>100000) { // 범위를 넘어서면 무시
                continue;
            }
            if(board[dir] != -1) { // 이미 방문한 부분은 무시
                continue;
            }
            board[dir] = board[cur]+1;
            que.push(dir);
        }
    }
    cout << board[K];
    
    return 0;
}
