#include <bits/stdc++.h>
using namespace std;

// 25.02.24 부분합 (투포인터)
int N,S;
int arr[100005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    int start = 0;
    int end = 0;
    int len = N+1;
    long long sum = 0;

    while(end<N) {
        sum += arr[end];

        while(sum>=S) { // 합이 S가 될때 까지 진행
            len = min(len,end-start+1); // S이상이 되면 길이 계산
            sum -= arr[start++]; // 최소길이를 구하기 위해 arr[start]를 빼고 start++로 투포인터 인덱스 증가
        }
        end++; // 반대로 합이 S가 되기 직전이므로 계속해서 투포인터 end인덱스 증가
    }

    if(len==N+1) cout << 0;
    else cout << len;

    return 0;
}
