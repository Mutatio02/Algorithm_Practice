#include <bits/stdc++.h>
using namespace std;
// 25.02.10 로프(그리디)
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> v(N);

    for(int i=0; i<N; i++) {
        cin >>  v[i];
    }

    sort(v.rbegin(),v.rend());
    
    int ans = 0;
    for(int i=0; i<N; i++) {
        ans = max(ans, v[i]*(i+1));
    }
    
    cout << ans;

    return 0;
}
