#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int gcd(int a,int b) {
    while(b!=0) {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
int lcm(int a,int b) {
    return a*b /gcd(a,b);
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c,d;
    cin >> a >> b;
    cin >> c >> d;
    
    int B = lcm(b,d);
    int A = a*(B/b) + c*(B/d);

    int mod = gcd(A,B);

    A /= mod;
    B /= mod;
    
    cout << A << " " << B;

    return 0;
}
