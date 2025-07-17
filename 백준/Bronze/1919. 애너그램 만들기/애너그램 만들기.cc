#include <bits/stdc++.h>
using namespace std;

// 25.07.17 에너그램 만들기
string first,second;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> first >> second;
    map<char,int> mp1,mp2;

    for(char c: first) {
        mp1[c]++;
    }
    
    for(char c: second) {
        mp2[c]++;
    }
    int cnt = 0;

    for(char ch = 'a'; ch<='z'; ch++) {
        cnt += abs(mp1[ch]-mp2[ch]); 
    }
    cout << cnt;
    return 0;
}
