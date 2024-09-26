#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    vector<string> v;

    for(int i=0; i<S.length(); i++) {
        v.push_back(S.substr(i));
    }
    sort(v.begin(),v.end());
    
    for(int i =0; i<v.size(); i++) {
        cout << v[i] << '\n';
    }
    return 0;
}
