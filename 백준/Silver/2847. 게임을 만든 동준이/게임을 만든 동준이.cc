#include <bits/stdc++.h>
using namespace std;

// 25.02.12 게임을 만든 동준이 (그리디)
int N;
int cnt = 0;
int arr[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }    

    for(int i=N-1; i>=1; i--) {
        if(arr[i] <= arr[i-1]) { // 크거나 같으면
            cnt += (arr[i-1] - arr[i] + 1); // 두 수의 차 + 1
            arr[i-1] = arr[i]-1; // 1 뺀 수로 만들기
        }
    }

    cout << cnt;

    return 0;
}
