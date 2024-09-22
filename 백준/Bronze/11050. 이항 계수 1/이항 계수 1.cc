#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    long long K;
    cin >> N >> K;
    long long result = 1;
    for(int i =0; i<K; i++) {
        result *= (N-i);
        result /= (i+1);
    }
    cout << result;
    return 0;
}