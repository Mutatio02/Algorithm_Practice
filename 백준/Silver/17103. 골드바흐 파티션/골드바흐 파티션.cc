#include <bits/stdc++.h>
using namespace std;

// 25.02.19 골드바흐 파티션 복습 (수학) 
int T;
const int MX =  1000000;
vector<bool> prime(MX + 1, true);
void base() {
    prime[0]=prime[1] = false;
    for(int i=2; i*i<=MX; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=MX; j+=i) {
                prime[j] = false;
            }   
        }
    }
}
void partition(int n) {
    int cnt = 0;
    for(int i=2; i<=n/2; i++) {
        int tmp = n-i;
        if(prime[i]&&prime[tmp]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    base();

    while(T--) {
        int N;
        cin >> N;
        partition(N);
    }

    return 0;
}
