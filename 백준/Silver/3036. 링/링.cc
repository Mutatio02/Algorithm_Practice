#include <bits/stdc++.h>
using namespace std;

// 25.02.19 링 (수학) 
int N;
int ring[1010];

int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> ring[i];
    }
    int base = ring[0];
    for(int i=1; i<N; i++) {
        int mod = gcd(base,ring[i]);
        cout << base/mod << '/' << ring[i]/mod << "\n";
    }
    
    return 0;
}
