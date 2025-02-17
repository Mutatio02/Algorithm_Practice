#include <bits/stdc++.h>
using namespace std;

// 25.02.17 베르트랑 공준 복습(수학) 
int N;

void check(int x) {
    int cnt = 0;
    if(x==1) {
        cout << 1 << "\n";
        return;
    }
    vector<bool> prime(2*x+1,true); // 소수 판별 배열
    prime[0] = prime[1] = false; //  0과 1은 소수가 아니다
    for(int i=2; i*i<=2*x; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=2*x; j+=i) { // 배수는 소수가 아니다
                prime[j] = false;
            }
        }
    }

    for(int i=x+1; i<=2*x; i++) {
        if(prime[i]) cnt++;
    }

    cout << cnt << "\n";
    return;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> N;
        if(N==0) break;
        check(N);
    }
    
    return 0;
}
