#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;

    while(true) {
        v.push_back(N%10);
        N/=10;

        if(N < 1)
            break;
    }
    
    sort(v.begin(),v.end(),greater<int>());
    
    for(int i=0; i<v.size(); i++) {
        cout << v[i];
    }

    return 0;
}
