#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,K;
    cin >> N >> K;

    vector<int> v(N);
    int poz = N-1; // 맨 마지막으로 초기화
    for(int i=0; i<N; i++) {
        cin >> v[i];

        if(v[i] > K) {
            poz = i-1;
        }           
    }

    sort(v.begin(),v.end());

    
    int cnt = 0;
    for(int i=poz; i>=0; i--) {
        cnt += K/v[i];
        K = K%v[i];
    }
    cout << cnt;

    
    

    return 0;
}
