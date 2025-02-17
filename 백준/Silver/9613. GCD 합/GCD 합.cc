#include <bits/stdc++.h>
using namespace std;

// 25.02.17 GCD 합(수학) 
int T;

int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        vector<int> v(n,0);
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }

        long long sum = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                sum += gcd(v[i],v[j]); 
            }
        }

        cout << sum << "\n";

    }
    
    return 0;
}
