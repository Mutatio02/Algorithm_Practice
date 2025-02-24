#include <bits/stdc++.h>
using namespace std;

// 25.02.24 수 고르기 (투포인터)
long long arr[200005];
int N,M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);

    int start = 0;
    int end = 0;
    long long ans = LONG_LONG_MAX;

    while(end<N) {
        long long sub = arr[end] - arr[start];

        if(sub>=M) { // 차이가 M 이상
            ans = min(ans,sub);
            start++; // 더 작은 값을 찾기 위해 증가
        }
        else end++; // 차이가 나지 않기 때문에 증가해서 찾기
    }

    cout << ans;

    return 0;
}
