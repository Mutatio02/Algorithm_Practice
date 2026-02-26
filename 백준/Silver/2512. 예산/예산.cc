#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<int> v(N,0);
    for(int i=0; i<N; i++) cin >> v[i];
    sort(v.begin(),v.end());
    
    long long M; 
    cin >> M;

    long long left = 0;
    long long right = *max_element(v.begin(),v.end());
    long long ans = 0;
    
    while(left<=right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        
        for (long long x : v) sum += min(x,mid);

        if(sum<=M) {
            ans = mid;
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    
    cout << ans;

    return 0;
}