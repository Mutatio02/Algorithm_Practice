#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,k;
    cin >> N >> k;

    vector<int> v(N,0);

    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end(),greater<int>());
    
    cout << v[k-1];
    return 0;
}
