#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> v(N);      //원본    
    vector<int> sorted_v(N);    // 수정

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        sorted_v[i] = v[i];  
    }

    sort(sorted_v.begin(), sorted_v.end());
    sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());

    for (int i = 0; i < N; i++) {
        int idx = lower_bound(sorted_v.begin(), sorted_v.end(), v[i]) - sorted_v.begin();// 수정 정렬된것에서 원본을 통해 파악 하는 것
        cout << idx << " ";
    }

    return 0;
}