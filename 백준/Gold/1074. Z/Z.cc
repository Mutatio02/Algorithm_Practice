#include <bits/stdc++.h>
using namespace std;
// 25.01.01  Z 복습
int N,r,c;

int solve (int n,int r,int c) {
    if(n==0) return 0;
    int len = 1 << (n-1);
    // 왼쪽 위
    if(r<len && c<len) return solve(n-1,r,c);
    // 오른쪽 위
    if(r<len && c>=len) return len*len + solve(n-1,r,c-len);
    // 왼쪽 아래
    if(r>=len && c<len) return len*len*2 + solve(n-1,r-len,c);
    // 오른쪽 아래
    return len*len*3 + solve(n-1,r-len,c-len);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> r >> c;
    int result = solve(N,r,c);

    cout << result;
    return 0;
}
