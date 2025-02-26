#include <bits/stdc++.h>
using namespace std;

// 25.02.26 싸이버개강총회 (해시)
string S,E,Q;
int cnt = 0;
int calcultime(string tmp) {
    string H = tmp.substr(0,2);
    string M = tmp.substr(3,2);

    int HM = 60 * stoi(H) + stoi(M);
    return HM;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> E >> Q;
    int start = calcultime(S);
    int end = calcultime(E);
    int stream = calcultime(Q);

    unordered_set<string> before; // key-value 기반의 해시가 아닌 
    unordered_set<string> after; // 중복되지 않는 key만 필요
        
    while(true) {
        string t,name;
        cin >> t >> name;

        if(cin.eof()==true) break;
        
        if(calcultime(t) <= start) { // 개강총회 시작 전
            before.insert(name);
        }
        else if(calcultime(t) >= end && calcultime(t)<=stream) {
            if(before.find(name)!=before.end()) {
                after.insert(name);
            }
        }

        
    }

    cout << after.size();

    return 0;
}
