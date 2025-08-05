#include <bits/stdc++.h>
using namespace std;
// 25.08.05 올림픽
int N,K;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    vector<tuple<int,int,int,int>> arr(N);
    for(int i=0; i<N; i++) {
        int n,g,s,b;
        cin >> n >> g >> s >> b;
        arr[i] = {n,g,s,b};
    }
    int tg,ts,tb;
    for (auto[n,g,s,b]: arr) {
        if(n==K) {
            tg = g;
            ts = s;
            tb = b;
        }
    }

    int rank = 1;
    for(auto[n,g,s,b]: arr) {
        if(g>tg) rank++;
        else if(g==tg && s > ts) rank++;
        else if(g==tg && s == ts && b>tb)rank++;
    }
    cout << rank;
    
    return 0;
}
