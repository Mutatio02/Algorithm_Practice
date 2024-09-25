#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b,c,d;
    cin >> a >> b >> c >>d;

    long long one = stoll(a+b);
    long long two = stoll(c+d);
    cout << one + two;
    return 0;
}
