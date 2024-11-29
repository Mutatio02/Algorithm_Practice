#include <bits/stdc++.h>
using namespace std;

int N;
int cnt = 0;
bool first[32]; // 같은 열
bool second[32]; // 왼쪽 대각선 
bool third[32]; // 오른쪽 대각선
/* N의 최대는 15(16이라 가정) 대각선의 개수를 나타내기 위해선 
   2*N -1 성립 필요 */

void solve(int cur) { // cur가 N번쨰 행 도착 -- 즉 (cur가 행) 
    if(cur == N) { // N번쨰 행까지 넣는데 성공한 경우
        cnt++; // 수를 증가
        return;
    }

    for(int i=0; i<N; i++) { // 열
        if(first[i] || second[cur+i] || third[cur-i+N-1]) {
            continue; // 이미 해당 열이나 대각선에 도착한 경우 무시
        }

        first[i] = true;  
        second[cur+i] = true; 
        third[cur-i+N-1] = true; 
        solve(cur+1);

        first[i] = false;
        second[cur+i] = false;
        third[cur-i+N-1] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    solve(0);

    cout << cnt;

    return 0;
}
