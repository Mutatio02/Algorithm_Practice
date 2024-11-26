#include <bits/stdc++.h>
using namespace std;

vector<string> board;
int N;

void QuadTree(int row,int col, int len) {
    bool Iszero = true;
    bool Isone = true;

    if(len == 1) { // 길이가 1이 되면 종료 
        cout << board[row][col]; // 1이 되는 순간의 입력을 처리
        return;
    }

    for(int i=row; i<row+len; i++) {
        for(int j=col; j<col+len; j++) {
            if(board[i][j] != '0') {
                Iszero = false;
            }
            if(board[i][j] !='1') {
                Isone = false;
            }
        }
    }
    if(Iszero) {
        cout << 0;
    }
    else if(Isone) {
        cout << 1;
    }
    else {
        cout << "(";
        QuadTree(row,col,len/2);
        QuadTree(row,col+len/2,len/2);
        QuadTree(row+len/2,col,len/2);
        QuadTree(row+len/2,col+len/2,len/2);
        cout << ")";
    }
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    board.resize(N);

    for(int i=0; i<N; i++) {
        cin >> board[i];
    }
    QuadTree(0,0,N);

    return 0;
}
