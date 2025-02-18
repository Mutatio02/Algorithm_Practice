#include <bits/stdc++.h>
using namespace std;

// 25.02.18 수 복원하기 (수학) 
int T;

void calcul(long long n) {
    for(int i=2; i*i<=n; i++) {
        int cnt = 0;
        while(n%i==0) {
            cnt++;
            n/=i;
        }
        if(cnt>0) cout << i << ' ' << cnt << "\n"; // 소인수 분해 출력
    }
    if(n>1) cout << n << ' ' << 1 << "\n"; // 남은 소수가 있는 경우 출력
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        long long N;
        cin >> N;
        calcul(N);        
    }
     
    return 0;
}
