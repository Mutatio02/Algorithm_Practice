#include <bits/stdc++.h>
using namespace std;
// 25.02.09 동전 0 (그리디)

int N;
long long K;
int coin[15];
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i=1; i<=N; i++) {
        cin >> coin[i];
    }

    for(int i=N; i>=1; i--) { // 최소 개수를 위해 큰 값부터 
        cnt += K/coin[i];
        K%=coin[i];
    }
    cout << cnt;

    return 0;
}
