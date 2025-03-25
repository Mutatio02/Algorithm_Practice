#include <bits/stdc++.h>
using namespace std;

// 25.03.24 랜선 자르기 복습(이분 탐색)

int K,N;
int line[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    int limit = 0;
    for(int i=0; i<K; i++) {
        cin >> line[i];
        limit = max(limit,line[i]);
    }

    long long left = 1;
    long long right = limit;
    long long ans = 0;

    while(left<=right) {
        long long mid = (left + right)/2;
        int cnt = 0;

        for(int i=0; i<K; i++) {
            cnt += line[i]/mid;
        }

        if(cnt>=N) {
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
