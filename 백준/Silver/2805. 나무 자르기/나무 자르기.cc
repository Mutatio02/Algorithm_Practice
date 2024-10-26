#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N,M;
    cin >> N >> M;

    vector<long long> v(N,0);
    for(long long i=0; i<N; i++) {
        cin >> v[i];
    }
    long long high = *max_element(v.begin(),v.end()); // 가장 큰수
    long long low = 0;
    long long result = 0;
    while(low <= high) {
        long long middle = (low+high)/2;
        long long length = 0;
        for(long long i=0; i<N; i++) {
            if(v[i]>middle) {
                length += v[i]-middle;
            }
        }

        if(length>=M) {
            result = middle;
            low = middle+1;
        }
        else {
            high = middle-1;
        }

    }
    cout << result;
    
    return 0;
}