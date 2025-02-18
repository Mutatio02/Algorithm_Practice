#include <bits/stdc++.h>
using namespace std;

// 25.02.18 LCM (수학) 
int T;
// 오버 플로우 방지를 위해 long long사용
long long gcd(int x,int y) {
    if(y==0) return x;
    return gcd(y,x%y);
}

long long lcm(int x,int y) {
    return x / gcd(x,y) * y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        long long a,b;
        cin >> a >> b;
        cout << lcm(a,b) << "\n";
    }
    
    return 0;
}
