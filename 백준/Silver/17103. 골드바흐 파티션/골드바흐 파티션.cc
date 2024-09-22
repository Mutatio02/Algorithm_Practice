#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool prime[1000001];
    for(int i=0; i<1000001; i++) {
        prime[i] = true;
    }
    prime[1] = false;
    for(int i=2; i<1000001; i++) {
        for(int j=2*i; j<1000001; j+=i) {
            prime[j] = false;
        }
    }

    int T;
    cin >> T;
    vector<int> ans;

    while(T--) {
        int N;
        cin >> N;

        int count = 0;

        for(int i=2; i<=N/2; i++) {
            if(prime[i] && prime[N-i]) {
                count++;
            }
        }
        cout << count << '\n';
    }

    

    return 0;
}
