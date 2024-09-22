#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> p(N);

    for(int i=0; i<N; i++) {
        cin >> p[i];
    }
    sort(p.begin(),p.end());
    
    int total_time = 0;
    int tmp = 0;
    for(int i=0; i<N; i++) {
        tmp += p[i];
        total_time+=tmp;
    }

    cout << total_time;
    return 0;
}
