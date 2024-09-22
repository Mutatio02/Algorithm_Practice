#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int x, y;
    vector<int> v1;
    vector<int> v2;

    while(N--) {
        cin >> x >> y;
        v1.push_back(x);
        v2.push_back(y);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    if(v1.size() ==1 || v2.size() ==1) {
        cout << 0;
    }
    else {
        cout << (v1.back()-v1.front()) * (v2.back()-v2.front());
    }
    
    return 0;
}
