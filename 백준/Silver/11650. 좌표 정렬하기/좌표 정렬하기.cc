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

    vector<pair<int,int>> v(N);

    for(int i=0; i<N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(),v.end());

    for(auto dot : v) {
        cout << dot.first << " " << dot.second << '\n';
    }
    return 0;
}
