#include <bits/stdc++.h>
using namespace std;

// 25.02.21 차집합 (이분탐색) 
int A,B;
vector<long long> a,b,v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    for(int i=0; i<A; i++) {
        long long num;
        cin >> num;
        a.push_back(num);
    }
    for(int j=0; j<B; j++) {
        long long num;
        cin >> num;
        b.push_back(num);   
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(auto n : a) {
        if(!binary_search(b.begin(),b.end(),n)) {
            v.push_back(n);
        }
    }

    if(v.size()==0) {
        cout << 0;
        return 0;
    }
    cout << v.size() << "\n";

    for(int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
    return 0;
}
