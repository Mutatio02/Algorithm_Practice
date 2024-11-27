#include <bits/stdc++.h>
using namespace std;

int board[129][129];
int N;
int white = 0;
int blue = 0;
// 24.11.27 -- 색종이 만들기 복습
bool IsEqual(int r,int c, int size) {
    for(int i= r; i<r+size; i++) {
        for(int j=c; j<c+size; j++) {
            if(board[r][c]!=board[i][j])
                return false;
        }
    }
    return true;
}
void partition(int r,int c,int idx) {
    if(IsEqual(r,c,idx)) {
        if(board[r][c] == 0) {
            white++;
        }
        else{
            blue++;
        }
        return;
    }
    int div = idx/2;

    partition(r,c,div);
    partition(r,c+div,div);
    partition(r+div,c,div);
    partition(r+div,c+div,div);
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }    
    partition(0,0,N);

    cout << white << "\n" << blue;
    return 0;
}
