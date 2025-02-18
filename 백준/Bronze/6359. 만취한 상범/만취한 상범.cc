#include <bits/stdc++.h>
using namespace std;

// 25.02.18 만취한 상범 (수학) 
int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<bool> v(n+1,true);

        for(int idx=2; idx<=n; idx++) {
            for(int i=idx; i<=n; i+=idx) {
                v[i] = !v[i];
            }
        }
        
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(v[i]) cnt++;
        }
        cout << cnt << "\n";
    }    
    return 0;
}
