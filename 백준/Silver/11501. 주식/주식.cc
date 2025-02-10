#include <bits/stdc++.h>
using namespace std;
// 25.02.11 주식 (그리디)
int T;
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;
        vector<int> v(N);
        long long ans = 0;

        for(int i=0; i<N; i++) {
            cin >> v[i];
        }
        int big = 0;

        for(int i=N-1; i>=0; i--) {
            if(v[i] >big) big = v[i];
            ans += (big - v[i]); 
        }
        cout << ans << "\n";
    }

    return 0;
}
