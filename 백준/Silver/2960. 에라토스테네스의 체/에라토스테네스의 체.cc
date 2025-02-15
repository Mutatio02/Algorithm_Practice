#include <bits/stdc++.h>
using namespace std;

// 25.02.15 에라스토네스의 체(수학) 
int N,K;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    vector<bool> arr(N+1,false);

    for(int i=2; i<=N; i++) {
        if(arr[i]) continue; // true는 지운 수 
        for(int j=i; j<=N; j+=i) { // 배수
            if(arr[j]) continue;
            arr[j] = true;
            K--;
            if(K==0) {
                cout << j;
                return 0;
            }
        }
    }
    return 0;
}
