#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool isPrime(int n) {
    if(n==1)    return false;
    if(n==2)    return true;
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> result;

    while(true) {
        int N;
        cin >> N;
        if(N==0) {
            break;
        }

        int count = 0;
        for(int i=N+1; i<=2*N; i++) {
            if(isPrime(i)) {
                count++;
            }
        }  
        result.push_back(count);
    }
    
    for(int c : result) {
        cout << c << '\n';
    }

    return 0;
}
