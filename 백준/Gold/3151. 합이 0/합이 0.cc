#include <bits/stdc++.h>
using namespace std;

// 25.02.23 합이 0  (이분탐색) --> 투포인터?
int N;
int arr[20005];
int team = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }    
    sort(arr,arr+N);

    long long ans = 0;

    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            long long sum = arr[i] + arr[j]; // 첫번째 두번째 수를 택함

            auto idx1 = lower_bound(arr+j+1,arr+N,-sum); // 나머지 세번쨰 수는 j+1부터 탐색 (처음 나오는 경우)
            auto idx2 = upper_bound(arr+j+1,arr+N,-sum); // 나중에 나오는 경우

            ans += (idx2 - idx1);
        }
    }
    
    cout << ans;

    return 0;
}
