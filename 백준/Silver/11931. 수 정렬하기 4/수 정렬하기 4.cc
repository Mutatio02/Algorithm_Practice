#include <bits/stdc++.h>
using namespace std;
// 25.1.31 정렬4
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> v(N);

    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end(),greater<int>());

    for(int i=0; i<N; i++) {
        cout << v[i] <<  "\n";
    }

    return 0;
}
