#include <bits/stdc++.h>
using namespace std;

int N,S; // 부분수열 개수, 합
int board[21];
int cnt = 0;

void solve(int idx, int sum) {
    if(idx == N) { 
        if(sum ==S) cnt++;
        return;
    }

    solve(idx+1,sum);

    solve(idx+1,sum+board[idx]);

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for(int i=0; i<N; i++) {
        cin >> board[i];
    }
    solve(0,0);
    if(S == 0) cnt--;

    cout << cnt;
    return 0;
}
