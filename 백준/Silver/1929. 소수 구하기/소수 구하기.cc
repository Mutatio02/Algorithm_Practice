#include <bits/stdc++.h>
using namespace std;

// 25.02.13 소수 구하기 (수학) 
long long N,M;


bool isPrime(int x) {
    if(x<2) return false;
    for(int i=2; i*i <=x; i++) {
        if(x%i ==0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for(int i=M; i<=N; i++) {
        if(isPrime(i)) {
            cout << i << "\n";
        }
    }


    

    return 0;
}
