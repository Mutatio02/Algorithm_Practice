#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long gcd (long long a,long long b) {
    if(a <b)    swap(a,b);
    while(b!=0) {
        int tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}
long long lcm(long long a,long long b) {
    return a*b / gcd(a,b);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A,B;
    cin >> A >> B;
    cout << gcd(A,B) << '\n';
    cout << lcm(A,B);
    return 0;
}