#include <bits/stdc++.h>
using namespace std;

// 25.02.19 토너먼트 (수학) 
int N,a,b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> a >> b;

    int round = 0;
    while(a!=b) {
        N/=2;
        a = (a+1)/2;
        b = (b+1)/2;
        round ++;
    }

    cout << round;
    
    return 0;
}
