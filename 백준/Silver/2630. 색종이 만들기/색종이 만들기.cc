#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int board[129][129];
int white = 0, blue = 0;

void Search(int x,int y, int size) {
    int tmp = board[x][y];
    bool isEqual = true;
    for(int i=x; i<x+size; i++) {
        for(int j=y; j<y+size; j++) {
            if(board[i][j] != tmp) {
                isEqual = false;
                break;
            }
        }
        if(!isEqual)    break;
    }
    if(isEqual) {
        if(tmp ==0) white++;
        else    blue++;
    }
    else {
        int tmpsize = size/2;
        Search(x,y,tmpsize); // I
        Search(x+tmpsize,y,tmpsize); // II
        Search(x,y+tmpsize,tmpsize); // III
        Search(x+tmpsize,y+tmpsize,tmpsize); // IV
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        } // 파랑은 1 하양은 0
    }
    Search(0,0,N);    
    cout << white << '\n' << blue;
    return 0;
}
