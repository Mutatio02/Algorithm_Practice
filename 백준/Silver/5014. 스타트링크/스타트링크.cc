#include <bits/stdc++.h>
using namespace std;
// 24.12.30 --스타트 링크 복습

int board[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int F,S,G,U,D;
    cin >> F >> S >> G >> U >> D;


    for(int i=1; i<=F; i++) { // 1층부터 F층까지 초기화
        board[i] = -1; 
    }

    queue<int> que;
    que.push(S); // S층은 현재 위치
    board[S] = 0; // 현재 위치는 0

    while(!que.empty()) {
        int cur = que.front();
        que.pop();

        for(auto dir: {cur+U,cur-D}) {
            if(dir<=0|| dir>F) continue;
            if(board[dir] !=-1) continue;
            board[dir] = board[cur]+1;
            que.push(dir);
        }
    }

    if(board[G] == -1) {
        cout << "use the stairs";
    }
    else {
        cout << board[G];
    }
    

    return 0;
}
