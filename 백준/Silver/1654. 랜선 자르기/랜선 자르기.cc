#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K,N;
    cin >> K >> N;
    vector<int> v(K);
    int max_length = 0;
    for(int i=0; i<K; i++){
        cin >> v[i];
        max_length = max(max_length,v[i]);
    }

    sort(v.begin(),v.end());

    long long left = 1;
    long long right = max_length;
    long long result = 0;

    while(left<=right) {
        long long middle = (left + right) / 2;
        int cnt = 0;
        for(int i=0; i<K; i++) {
            cnt += v[i] / middle;
        }

        if(cnt >=N) {
            result = middle;
            left = middle + 1;
        }
        else {
            right = middle -1;
        }
    }

    cout << result;
    return 0;
}
