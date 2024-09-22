#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    int M;
    cin >>M;

    int search;
    for(int i=0; i<M; i++) {
        cin >> search; // 마지막 등장 위치의 다음 - 처음 등장한 위치
        cout << upper_bound(v.begin(),v.end(),search) - lower_bound(v.begin(),v.end(),search)<< " ";
    }

    return 0;
}