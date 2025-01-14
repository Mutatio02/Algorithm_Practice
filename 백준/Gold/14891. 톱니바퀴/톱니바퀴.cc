#include <bits/stdc++.h>
using namespace std;

char board[4][8]; // N극은 0, S극은 1
int k, score = 0;

void cal() {
    if (board[0][0] == '1') score += 1;
    if (board[1][0] == '1') score += 2;
    if (board[2][0] == '1') score += 4;
    if (board[3][0] == '1') score += 8;
}

void rotate(int number, int dir) {
    vector<pair<int, int>> rotations;
    rotations.push_back({number, dir});

    int left_dir = dir, right_dir = dir;

    // 왼쪽 톱니바퀴
    for (int i = number - 1; i >= 0; i--) {
        if (board[i][2] != board[i + 1][6]) {
            left_dir = -left_dir;
            rotations.push_back({i, left_dir});
        } else {
            break;
        }
    }

    // 오른쪽 톱니바퀴
    for (int i = number + 1; i < 4; i++) {
        if (board[i][6] != board[i - 1][2]) {
            right_dir = -right_dir;
            rotations.push_back({i, right_dir});
        } else {
            break;
        }
    }

    for (auto rot : rotations) {
        deque<char> dq(board[rot.first], board[rot.first] + 8);

        if (rot.second == 1) { // 시계 방향
            dq.push_front(dq.back());
            dq.pop_back();
        } else if (rot.second == -1) { // 반시계 방향
            dq.push_back(dq.front());
            dq.pop_front();
        }

        for (int i = 0; i < 8; i++) {
            board[rot.first][i] = dq[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 8; j++) {
            board[i][j] = line[j];
        }
    }

    cin >> k;

    while (k--) {
        int number, dir;
        cin >> number >> dir;
        number--;  // 0-based index
        rotate(number, dir);
    }

    cal();
    cout << score;
    return 0;
}
