#include <bits/stdc++.h>
using namespace std;

// 25.02.21 세 수의 합 (이분탐색) 
int N;
long long arr[1010];
vector<long long> sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    
    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            sum.push_back(arr[i]+arr[j]); // 2개 수의 합 구하기
        }
    }
    sort(sum.begin(),sum.end());
    
    for(int i=N-1; i>0; i--) {
        for(int j=0; j<i; j++) {
            long long target = arr[i] - arr[j]; // K는 U집합의 임의의 수
            // k-(임의의 수) = sum집합의 원소인지 확인
            
            if(binary_search(sum.begin(),sum.end(),target)) {
                cout << arr[i];
                return 0;
            }
        }
    }
    return 0;
}
