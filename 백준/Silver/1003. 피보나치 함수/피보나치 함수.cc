#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    int zero[41] = {1,0}; // 1,0 이후 피보나치 수열
    int one[41] = {0,1}; // 0,1 이후 피노나치 수열

    while(T--) {
        int N;
        cin >> N;
        
        for(int i=2; i<=N; i++) {
            zero[i] = zero[i-1] +zero[i-2];
            one[i] = one[i-1] + one[i-2];
        }
        cout << zero[N] << " " << one[N] << '\n';
    }
    
    return 0;
}
