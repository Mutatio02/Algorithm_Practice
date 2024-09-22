#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int L;
    cin >> L;

    string str;
    cin >> str;

    long long r = 31;
    long long M = 1234567891;
    long long pow_r = 1; // 거듭제곱을 직접 계산 해야됨
    long long sum = 0;

    for(int i=0; i<L; i++) {
        sum = (sum + (str[i]-'a'+1) * pow_r) % M;
        pow_r = (pow_r * r) % M; // 1*r mod M 은 r, r의 제곱...
    }

    cout << sum;
    return 0;
}