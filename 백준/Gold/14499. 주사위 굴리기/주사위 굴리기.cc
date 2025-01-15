#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, k;
int board[21][21]; // 지도
int dx[4] = {0, 0, -1, 1}; // 동, 서, 북, 남
int dy[4] = {1, -1, 0, 0};
int dice[6] = {}; // 주사위 면 상태 (위, 아래, 북, 남, 동, 서)

// 주사위를 굴리는 함수
void roll(int dir) {
    int tmp[6];
    for(int i=0; i<6; i++) {
        tmp[i] = dice[i];
    }
    if (dir == 0) { // 동
        dice[0] = tmp[3];
        dice[1] = tmp[2];
        dice[2] = tmp[0];
        dice[3] = tmp[1];
    } else if (dir == 1) { // 서
        dice[0] = tmp[2];
        dice[1] = tmp[3];
        dice[2] = tmp[1];
        dice[3] = tmp[0];
    } else if (dir == 2) { // 북
        dice[0] = tmp[4];
        dice[1] = tmp[5];
        dice[4] = tmp[1];
        dice[5] = tmp[0];
    } else if (dir == 3) { // 남
        dice[0] = tmp[5];
        dice[1] = tmp[4];
        dice[4] = tmp[0];
        dice[5] = tmp[1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> x >> y >> k;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    while (k--) {
        int order;
        cin >> order;
        order -= 1; 

        // 이동하려는 좌표
        int nx = x + dx[order];
        int ny = y + dy[order];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;

        x = nx;
        y = ny;
        roll(order);

        if (board[x][y] == 0) {
            board[x][y] = dice[1]; 
        } else {
            dice[1] = board[x][y]; // 지도의 숫자를 주사위 바닥에 복사
            board[x][y] = 0;       // 지도를 0으로 변경
        }

        cout << dice[0] << '\n';
    }

    return 0;
}