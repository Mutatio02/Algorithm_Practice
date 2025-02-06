#include <bits/stdc++.h>
using namespace std;
// 25.02.06 피보나치 함수(dp복습)
int T;
int zero[45] = {1,0}; // 0의 개수 테이블
int one[45] = {0,1}; // 1의 개수 테이블

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    
    while(T--) {
        int N;
        cin >> N;

        for(int i=2; i<=N; i++) {
            zero[i] = zero[i-1]+zero[i-2];
            one[i] = one[i-1]+one[i-2];
        }
        cout << zero[N] << ' ' << one[N] << "\n";
    }
    
}
