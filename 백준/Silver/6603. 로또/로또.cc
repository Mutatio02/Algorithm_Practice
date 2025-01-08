#include <bits/stdc++.h>
using namespace std;
// 25.01.08 백트레킹 복습 (로또)

int k;
int board[50];
int output[6];
void back_track(int idx,int start) {
    if(idx==6) {
        for(int i=0; i<6; i++) {
            cout << output[i] << ' ';
        }
        cout << "\n";
        return;
    }
    
    for(int i=start; i<k; i++) {
        output[idx] = board[i];
        back_track(idx+1,i+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1) {
        cin >> k;
        if(k==0) break;

        fill(board,board+k,0);
         
        for(int i=0; i<k; i++) {
            cin >> board[i];
        }

        back_track(0,0);
        
        cout << "\n";
    }
    
    return 0;
}