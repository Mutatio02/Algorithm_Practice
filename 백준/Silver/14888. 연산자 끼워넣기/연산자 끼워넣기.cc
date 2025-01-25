#include <bits/stdc++.h>
using namespace std;
// 25.01.25 시뮬레이션(연산자 끼워넣기)
// idx를 사용한것 까지는 알았으나 매개변수로 같이 현재값을 넘겨주는 부분을 생각히자 못함
int N;
int board[12];
int op[4]; // 연산자(순서대로 +,-,*,/ )
int big = INT_MIN; // 최대값
int small = INT_MAX; // 최소값
void simulation(int idx,int cur) { // idx와 현재값
    if(idx == N) {
        big = max(big,cur);
        small = min(small,cur);
        return;
    }
    for(int i=0; i<4; i++) {
        if(op[i]>0) {
            op[i]--; // 백트래킹 시작
            if(i==0) simulation(idx+1,cur+board[idx]);
            else if(i==1) simulation(idx+1,cur-board[idx]);
            else if(i==2) simulation(idx+1,cur*board[idx]);
            else simulation(idx+1,cur/board[idx]);
            op[i]++; // 복구
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> board[i];
    }

    for(int i=0; i<4; i++) {
        cin >> op[i];
    }
    
    simulation(1,board[0]);
    cout << big << "\n" << small;
    return 0;
}
