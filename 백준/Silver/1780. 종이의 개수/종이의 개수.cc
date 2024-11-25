#include <bits/stdc++.h>
using namespace std;

int N;
int board[3001][3001];
int cnt[3];
bool check(int s,int e, int size) { // 범위에 맞추어 같은지 아닌지 비교
    for(int i = s; i<s+size; i++) {
        for(int j=e; j<e+size; j++) {
            if(board[s][e] != board[i][j])
                return false;
        }
    }
    return true;
}
void partition(int start,int end, int size) {
    if(check(start,end,size)) {
        cnt[board[start][end]+1] +=1; // -1 0 1 값이 각각 0 1 2 idx에 해당됨
        return;
    }
    int newsize = size / 3;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            partition(start + i*newsize,end + j*newsize,newsize);
        }
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j= 0; j<N; j++) {
            cin >> board[i][j];
        }
    }    
    partition(0,0,N);

    for(int i=0; i<3; i++) {
        cout << cnt[i] << "\n";
    }
    return 0;
}
