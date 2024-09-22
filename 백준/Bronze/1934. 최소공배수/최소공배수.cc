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

    int T;
    cin >> T;

    while(T--) {
        int A,B;
        cin >> A >> B;
        if(A<B) {
            swap(A,B);
        }
        cout << lcm(A,B) << '\n';
    }


    return 0;
}
