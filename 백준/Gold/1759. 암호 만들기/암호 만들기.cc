#include <bits/stdc++.h>
using namespace std;

int L,C;
char board[25];
char output[25];
bool check(char ch) { // 모음 확인
    return ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u';
}
void solve(int idx,int start) {
    if(idx == L) {
        bool flag = false;
        int cnt1 = 0; // 모음은 적어도 1개
        int cnt2 = 0; // 자음은 적어도 2개
        for(int i=0; i<L; i++) {
            if(check(output[i])) {
                cnt1++;
            }
            else cnt2++;
        }
        if(cnt1 >=1 && cnt2>=2) {
            flag = true;
        }

        if(flag) {
            for(int i=0; i<L; i++) {
                cout << output[i];
            }
            cout << "\n";
        }
    }
    
    for(int i=start; i<C; i++) {
        output[idx] = board[i];
        solve(idx+1,i+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> C;
    for(int i=0; i<C; i++) {
        cin >> board[i];
    }
    sort(board,board+C);

    solve(0,0);

    return 0;
}
