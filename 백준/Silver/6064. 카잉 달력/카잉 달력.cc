#include <bits/stdc++.h>
using namespace std;

// 25.02.14 카잉달력 (수학) 
int T;
int gcd(int x,int y) {
    if(y==0) return x;
    else return gcd(y,x%y);
}
int lcm(int x,int y) {
    return x /gcd(x,y) * y;
}
int inka(int m,int n,int x, int y) {
    if(x==m) x = 0; // 같으면 0으로 계산
    if(y==n) y = 0;
    int l = lcm(m,n);
    for(int i=x; i<=l; i+=m) {
        if(i==0) continue;
        if(i%n==y) return i;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    while(T--) {
        int M,N,x,y;
        cin >> M >> N >> x >> y;
        cout << inka(M,N,x,y) << "\n";
    }
    

    return 0;
}
