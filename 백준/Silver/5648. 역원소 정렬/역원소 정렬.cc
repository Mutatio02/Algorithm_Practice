#include <bits/stdc++.h>
using namespace std;
// 25.2.2 역원소 정렬(정렬 II) 
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<long long> v(N,0);
    vector<long long> sort_v(N,0);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    
    for(int i=0; i<N; i++) {
        string str = to_string(v[i]);
        reverse(str.begin(), str.end());
        sort_v[i] = stoll(str);
    }
     
    sort(sort_v.begin(),sort_v.end());

    for(auto n : sort_v) {
        cout << n << "\n";
    }
    return 0;
}
