#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    vector<int> v(5,0);
    int sum = 0;

    for(int i=0; i<5; i++) {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(),v.end());
    
    cout << sum/5 << '\n' << v[2];
    return 0;
}
