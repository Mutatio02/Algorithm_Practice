#include <bits/stdc++.h>
using namespace std;
// 25.1.27 시뮬레이션(경사로)
// 가로 또는 세로열의 높이가 모두 같은 경우 --- 1번
// 인접한 칸이 L개 이상 같고 높이차이가 1인 경우 -- 2번
int N,L;
int board[101][101];
int cnt = 0;
void row(int idx) { // 가로
    bool check[101] ={};
    for(int j=0; j<N-1; j++) {
        if(board[idx][j] == board[idx][j+1]) continue; // 1번 경우

        if(abs(board[idx][j]-board[idx][j+1])>1 ) return;

        // 2번 경우
        if(board[idx][j] < board[idx][j+1]) { // 높이가 높아지는 경우
            for(int k=0; k<L; k++) { // L개 이전까지 같은지 확인
                if(j-k <0 || board[idx][j]!= board[idx][j-k] || check[j-k]) return;
                check[j-k] = true;
            }
        }
        else { // 높이가 낮아지는 경우 j+1 부터 경사로 설치 가능
            for(int k=0; k<L; k++) {
                if(j+k+1 >=N || board[idx][j+1] != board[idx][j+k+1] || check[j+k+1]) return;
                check[j+k+1] = true;
            }
        }
    }
    cnt++;
}
void col(int idx) { // 세로
    bool check[101] = {};

    for(int i = 0; i<N-1; i++) {
        if(board[i][idx] == board[i+1][idx]) continue;

        if(abs(board[i][idx] - board[i+1][idx])>1) return;

        if(board[i][idx] < board[i+1][idx]) {
            for(int k=0; k<L; k++) {
                if(i-k<0 || board[i][idx] != board[i-k][idx] || check[i-k]) return;
                check[i-k] = true;
            }
        }
        else {
            for(int k=0; k<L; k++) {
                if(i+k+1>=N || board[i+1][idx] != board[i+k+1][idx] || check[i+k+1]) return;
                check[i+k+1] = true;
            }
        }
    }
    cnt++;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        row(i);
    }
    for(int j=0; j<N; j++) {
        col(j);
    }
    cout << cnt;
    return 0;
}
