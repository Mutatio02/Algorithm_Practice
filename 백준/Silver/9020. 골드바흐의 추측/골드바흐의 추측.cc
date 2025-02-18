#include <bits/stdc++.h>
using namespace std;

// 25.02.18 골드바흐의 추측 (수학) 
int T;
vector<bool> v(10001,true);
void prime() {
    v[0] = v[1] = false;
    for(int i=2; i*i <= 10000; i++) {
        if(v[i]) {
            for(int j=i*i; j<=10000; j+=i) {
                v[j] = false;
            }
        }
    }
}
void partition(int n) {
    for(int i=n/2; i>=2; i--) { // 두 소수의 차이가 가장 작은 것을 위해 n/2 부터 찾기
        int j = n-i; // i가 소수라면 j는 n을 이루기 위한 다른 소수일 것
        if(v[i] && v[j]) {
            cout << i << ' ' << j << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    prime(); // 먼저 소수를 찾기 -- > 에라토스테네스의 체

    while(T--) {
        int n;
        cin >> n;
        partition(n);
    }
    return 0;
}
