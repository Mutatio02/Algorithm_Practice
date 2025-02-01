#include <bits/stdc++.h>
using namespace std;
// 25.2.2 수 정렬하기5(정렬 II) 
int N;
int board[2000001]; // 절대값 고려

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        board[a+1000000]++;
    }
    
    for(int i=0; i<2000001; i++) {
        while(board[i]--) {
            cout << i-1000000 << "\n";
        }
    }
    return 0;
}
