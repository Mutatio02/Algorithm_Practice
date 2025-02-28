#include <bits/stdc++.h>
using namespace std;

// 25.02.28 문제 추천 시스템 Version 1 (이진 탐색 트리)
int N,M;
multiset<pair<int,int>> pb;
map<int,int> mp;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--) {
        int P,L;
        cin >> P >> L; // 문제 난이도
        pb.insert({L,P}); // {난이도 문제}
        mp[P] = L; // 문제 난이도
    }


    cin >> M;
    while(M--) {
        string ord;
        cin >> ord;
        if(ord == "add") {
            int P,L;
            cin >> P >> L;
            pb.insert({L,P});
            mp[P] = L;
        }
        else if(ord == "solved") {
            int P;
            cin >> P;
            pb.erase({mp[P],P});
            mp.erase(P);
        }
        else {
            int X;
            cin >> X;
            if(X==1) {
                cout << (*prev(pb.end())).second << "\n";
            }
            else {
                cout << (*pb.begin()).second << "\n";
            }
        }
    }
    return 0;
}
