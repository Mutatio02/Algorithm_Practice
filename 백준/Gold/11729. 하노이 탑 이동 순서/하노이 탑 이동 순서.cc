#include <bits/stdc++.h>
using namespace std;
void solve(int a,int b,int n) { //a에서 b로 n개 이동
    if(n ==1) {
        cout << a << ' ' << b << '\n'; // 개수가 1개면 단순 이동
        return;
    }
    solve(a,6-a-b,n-1); // n-1개를 시작점에서 옮기기
    cout << a << ' ' << b << '\n'; // n번을 옮기기
    solve(6-a-b,b,n-1); // n-1개를  n번의 위치로 옮기기
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int tmp = 1;
    for(int i=0; i<N; i++) {
        tmp *= 2;
    }
    cout << tmp - 1 << '\n';
    solve(1,3,N);
    return 0;
}
