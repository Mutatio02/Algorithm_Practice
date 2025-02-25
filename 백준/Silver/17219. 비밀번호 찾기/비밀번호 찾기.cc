#include <bits/stdc++.h>
using namespace std;

// 25.02.25 비밀번호 찾기 복습 (해시)
int N,M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    unordered_map<string,string> site;

    while(N--) {
        string adrss,pswd;
        cin >> adrss >> pswd;
        site[adrss] = pswd;
    }

    while(M--) {
        string pb;
        cin >> pb;
        cout << site[pb] << "\n";
    }
    
    return 0;
}
