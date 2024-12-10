#include <bits/stdc++.h>
using namespace std;

int board[15]; // 입력
int S[15]; // 집합
int k;

void solve(int idx,int start) {
    if(idx == 6) { // 로또 번호는 6개
        for(int i=0; i<6; i++) {
            cout << S[i] << ' ';
        }
        cout << "\n";
        return;
    }

    int tmp = 0;
    for(int i=start; i<k; i++) {
        if(board[i]!=tmp) {
            S[idx] = board[i];
            tmp = board[i];
            solve(idx+1,i+1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1) {
        cin >> k;
        if(k==0) break;
        for(int i=0; i<k; i++) {
            cin >> board[i];
        }
        
        solve(0,0);
        cout << "\n";        
    }
    return 0;
}
