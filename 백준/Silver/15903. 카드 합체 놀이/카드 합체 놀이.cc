#include <bits/stdc++.h>
using namespace std;

// 25.02.13 카드 합체 놀이 (그리디)
int n,m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<long long> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    
    while(m--) {
        swap(v[0],*min_element(v.begin(),v.end()));
        swap(v[1],*min_element(v.begin()+1,v.end()));
        long long sum = v[0] + v[1];
        v[0] = sum;
        v[1] = sum;
    }

    long long ans = 0;
    for(int i=0; i<n; i++) {
        ans += v[i];
    }

    cout << ans;

    return 0;
}
