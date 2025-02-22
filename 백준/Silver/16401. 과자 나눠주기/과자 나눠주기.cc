#include <bits/stdc++.h>
using namespace std;

// 25.02.22 과자 니눠주기 (이분탐색) 
int M,N;
vector<long long> v;

bool check(int size) {
    long long cnt =0;
    for(int i=0; i<v.size(); i++) { // 과자의 길이들로 나눴을때
        cnt += v[i] / size;
    }
    return cnt >=M; // cnt가 M이상이라면 true
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    while(N--) {
        long long snack;
        cin >> snack;
        v.push_back(snack); 
    }

    sort(v.begin(),v.end());
    
    long long start = 1; // 길이는 1부터
    long long end = *max_element(v.begin(),v.end()); // 과자의 최대 길이까지
    long long ans = 0;

    while (start<=end) {
        long long mid = (start+end)/2 ;

        if(check(mid)) {
            ans = mid;
            start = mid +1;
        }
        else end = mid-1;
    }
    cout << ans;

    return 0;
}
