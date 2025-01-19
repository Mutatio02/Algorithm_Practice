#include <bits/stdc++.h>
using namespace std;
// 25.01.19 시뮬레이션(뱀) 
int N,k,L;
int board[101][101];
int cnt = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
deque<pair<int,int>> snake; // 뱀
queue<pair<int,int>> q; // 시간과 방향좌표

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> k;
    for(int i=0; i<k; i++) {
        int r,c;
        cin >> r >> c;
        board[r][c] = 2; // 사과
    }

    cin >> L;
    for(int i=0; i<L; i++) {
        int X;
        char C;
        cin >> X >> C;
        q.push({X,C});
    }

    snake.push_front({1,1}); // 1- based
    int dir = 1;

    while(true) {
        dir %=4;

        auto cur = snake.front();
        board[cur.first][cur.second] = 1; // 뱀
        cnt++;

        int nx = dx[dir]+cur.first;
        int ny = dy[dir]+cur.second;

        if(nx<1 || nx>N || ny<1 || ny>N) break;// 범위 지나면 멈추기
        if(board[nx][ny] ==1) break; // 자기 자신 몸통이면 멈추기
        
        if(board[nx][ny] != 2) {
            auto tail = snake.back(); // 꼬리
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }

        auto d = q.front();
        if(d.first == cnt) {
            if(d.second == 'L') {
                dir+=1;
            }
            else if(d.second == 'D') {
                dir+=3;
            }
            q.pop();
        }
        snake.push_front({nx,ny}); // 머리
    }
    cout << cnt;

    return 0;
}
