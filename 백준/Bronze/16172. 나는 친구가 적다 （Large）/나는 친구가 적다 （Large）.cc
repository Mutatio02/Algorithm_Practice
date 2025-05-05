#include <bits/stdc++.h>
using namespace std;
// 25.05.05 나는 친구가 적다 (Large)
string S;
string K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    cin >> K;

    string convert = "";
    for(char ch: S) {
        if(!isdigit(ch)) convert += ch;
    }

    if(convert.find(K) != string::npos) {
        cout << 1;
    }
    else cout << 0;
    
    return 0;
}
