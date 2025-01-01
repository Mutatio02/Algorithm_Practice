#include <bits/stdc++.h>
using namespace std;

long long A,B,C;
long long solve(long long a,long long b, long long c) {
    if(b==1) return a%c; // b가 1이면 결과는 a%c;
    long long tmp = solve(a,b/2,c);
    tmp= tmp*tmp%c;
    if(b%2 ==0) return tmp;
    return tmp*a%c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> C;
    long long result = solve(A,B,C);

    cout << result;
    return 0;
}
