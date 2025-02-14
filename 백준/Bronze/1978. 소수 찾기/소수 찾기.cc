#include <bits/stdc++.h>
using namespace std;

// 25.02.13 소수 찾기 복습 (수학) 
int N;
int arr[105];
int cnt = 0;

bool isprime(int x) {
    if(x<2) return false;
    for(int i=2; i*i <=x; i++) {
        if(x%i ==0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<N; i++) {
        if(isprime(arr[i])) cnt++;
    }

    cout << cnt;

    return 0;
}
