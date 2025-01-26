#include <bits/stdc++.h>
using namespace std;
// 25.01.26 시뮬레이션(스타트와 링크)
int N;
int board[21][21];
bool used[21];
int result = INT_MAX;

void simulation(int idx, int cnt) {
    if (cnt == N / 2) { // 팀이 2개
        int start = 0, link = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (used[i] && used[j]) start += board[i][j]; // 사용한 것은 start
                if (!used[i] && !used[j]) link += board[i][j]; // 사용하지 않은 것은 link
            }
        }
        result = min(result, abs(start - link)); 
        return;
    }

    for (int i = idx; i <= N; i++) { 
        if (!used[i]) {
            used[i] = true;
            simulation(i + 1, cnt + 1);
            used[i] = false; // 백트래킹
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    simulation(1, 0);
    cout << result;
    return 0;
}
