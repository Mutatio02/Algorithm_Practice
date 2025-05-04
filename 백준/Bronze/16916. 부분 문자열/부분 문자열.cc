#include <bits/stdc++.h>
using namespace std;
// 25.05.04 부분 문자열
string S,P;
set<string> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    cin >> P;
    
    if(strstr(S.c_str(),P.c_str()) != NULL) {
        cout << 1;
    }
    else cout << 0;
    
    return 0;
}
