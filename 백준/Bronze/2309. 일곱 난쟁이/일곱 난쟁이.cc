#include <bits/stdc++.h>
using namespace std;

// 25.03.11 일곱난쟁이 복습 
int arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N = 9;
    int sum = 0;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr,arr+N);

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if(sum-arr[i]-arr[j] ==100) { // 2명을 제외
                for(int k=0; k<N; k++) {
                    if(k!=i && k!=j) cout << arr[k] << "\n";
                }
                return 0;
            }
        }
    }
    
    return 0;
}