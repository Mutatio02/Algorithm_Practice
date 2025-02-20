#include <bits/stdc++.h>
using namespace std;

// 25.02.20 랜선 자르기 복습 (이분탐색) 
int K,N;
int line[10001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    int length = 0;
    for(int i=0; i<K; i++) {
        cin >> line[i];
        length = max(length,line[i]);
    }

    long long start = 1;
    long long end = length;
    long long result = 0;

    while(start<=end) {
        long long mid = (start+end)/2;
        int cnt = 0;
        
        for(int i=0; i<K; i++) {
            cnt += line[i]/mid; // mid로 나눴을떄
        }

        if(cnt>=N) { // 개수가 N개 이상
            result = mid; // 값은 mid가 될 것이다
            start = mid+1;
        }
        else { // N개 미만
            end = mid-1;
        }   
        
    }

    cout << result;

    return 0;
}
