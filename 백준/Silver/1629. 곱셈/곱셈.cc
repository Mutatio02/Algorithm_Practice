#include <bits/stdc++.h>
using namespace std;

long long calculate(long long a,long long b, long long c) {
    if(b == 1) return a%c; // b == 1 이면 결과 값은 a%c

    long long tmp = calculate(a,b/2,c); // 지수 법칙
    tmp = tmp*tmp % c;

    if(b%2 ==0) return tmp;
    return tmp*a % c; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A,B,C;
    cin >> A >> B >> C;
    
    cout << calculate(A,B,C);

    return 0;
}
