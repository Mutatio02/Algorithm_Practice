#include <bits/stdc++.h>
using namespace std;
// 25.02.10 보물(그리디)
int N;
int A[101];
int B[101];
int ans= 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    for(int i=0; i<N; i++) {
        cin >> B[i];
    }
    
    sort(A,A+N); // 오름차순
    sort(B,B+N,greater<int>()); // 내림차순

    for(int i=0; i<N; i++) {
        ans+= A[i] * B[i];
    }
    cout << ans;

    return 0;
}
