#include <bits/stdc++.h>
using namespace std;
// 25.2.2 카드(정렬 II) 

int N;
long long arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);

    int cnt = 1;
    long long val = -(1LL<<62)-1;
    int mxcnt = 0;

    for(int i=1; i<N; i++) { 
        if(arr[i] == arr[i-1]) { // 이전과 그 다음이 같으면 증가
            cnt++;
        }
        else { // 다음이 같지 않다면 
            if(cnt>mxcnt) {
                mxcnt = cnt;
                val = arr[i-1];
            }
            cnt = 1;
        }
    }

    if(cnt>mxcnt) { // 마지막의 개수가 더 많다면
        val = arr[N-1]; // 갱신하기
    }

    cout << val;
    return 0;
}
