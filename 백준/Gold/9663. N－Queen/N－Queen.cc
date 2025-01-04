#include <bits/stdc++.h>
using namespace std;
// 25.01.04 백트레킹 복습 (N-Queen)

int N;
bool line1[31]; // 열 
bool line2[31]; // 왼쪽 아래 대각선
bool line3[31]; // 오른쪽 아래 대각선
int cnt = 0;
void back_track(int cur) { // 행
    if(cur==N) {
        cnt++;
        return;
    }

    for(int i=0; i<N; i++) { // 열
        if(line1[i] || line2[i+cur] || line3[cur-i+N-1]) {
            continue;
        }
        
        line1[i] = true;
        line2[i+cur] = true;
        line3[cur-i+N-1] = true;

        back_track(cur+1);

        line1[i] = false;
        line2[i+cur] = false;
        line3[cur-i+N-1] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N; 
    back_track(0);

    cout << cnt;
    return 0;
}