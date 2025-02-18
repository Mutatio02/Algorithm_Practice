#include <bits/stdc++.h>
using namespace std;

// 25.02.18 거의 소수 (수학) 

long long A,B;
const long long MX = 10000001;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    vector<bool> prime(MX,true);
    vector<long long> v; // 소수 저장하기

    prime[0]=prime[1] = false;
    for(int i=2; i*i<= MX; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=MX; j+=i) {
                prime[j] = false;
            }
        }
    }
    
    for(int i=2; i<=MX; i++) {
        if(prime[i]) v.push_back(i);
    }
    
    int cnt = 0;
    
    for(auto p : v) {
        long long tmp = p*p;
        
        while(tmp<=B) {
            if(tmp>=A) cnt++;
            if(tmp>B/p) break;
            tmp *=p;
        }
    }
    
    cout << cnt;

    return 0;
}
