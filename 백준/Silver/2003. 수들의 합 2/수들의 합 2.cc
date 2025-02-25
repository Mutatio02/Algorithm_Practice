#include <bits/stdc++.h>
using namespace std;

// 25.02.25 수들의 합2 (투포인터)
int N;
long long M;
int arr[10005];
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    int start = 0;
    int end = 0;
    long long sum = 0;

    while(end<N) {
        sum += arr[end];

        while(sum>=M) {
            if(sum==M)cnt++;
            sum -= arr[start++];
        } 
        end++;
    }
    
    cout << cnt;

    return 0;
}
