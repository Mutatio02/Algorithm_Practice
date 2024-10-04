#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N,0);

    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end()); 

    int x;
    cin >> x;

    int left = 0; // 왼쪽에서 탐색
    int right = N-1; // 오른쪽(맨 끝)에서 탐색
    int cnt = 0;
    while(left<right) {
        if(v[left]+v[right] == x) {
            cnt++;
            left++;
            right--;
        }
        else if(v[left]+v[right] <x) { // 값보다 작으면 left를 증가
            left++;
        }
        else{ // 값보다 크면 right를 감소
            right--;
        }

    }
    cout << cnt;
    return 0;
}
