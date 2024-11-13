#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[8] = {1, 2, -1, -2, 1, 2, -1, -2};
int dy[8] = {2, 1, -2, -1, -2, -1, 2, 1};
int board[301][301];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int I;
        cin >> I;

        for (int i = 0; i < I; i++) {
            fill(board[i], board[i] + I, -1);
        }

        queue<pair<int, int>> q;
        pair<int, int> loc;
        pair<int, int> mov;
        cin >> loc.first >> loc.second;
        cin >> mov.first >> mov.second;

        if (loc == mov) {
            cout << 0 << "\n";
            continue;
        }

        q.push({loc.first, loc.second});
        board[loc.first][loc.second] = 0;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {  
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
                if (board[nx][ny] >= 0) continue;

                q.push({nx, ny});
                board[nx][ny] = board[cur.first][cur.second] + 1;
            }
        }

        cout << board[mov.first][mov.second] << "\n";
    }

    return 0;
}
