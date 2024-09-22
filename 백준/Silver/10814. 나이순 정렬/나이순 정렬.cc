#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool my_sort(const pair<int,string> a, const pair<int,string> b) {
    return a.first < b.first;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int,string>> v;
    pair<int,string> info;
    for(int i=0; i<N; i++) {
        cin >> info.first >> info.second;
        v.push_back(info);
    }

    stable_sort(v.begin(),v.end(),my_sort);

    for(auto user : v) {
        cout << user.first << " " << user.second << '\n';
    }

    return 0;
}
