#include <bits/stdc++.h>
using namespace std;
// 2025.03.19 반복(그리디)
string S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;

    int cnt = 1; // 최소 1번은 반복 필요
    for(int i = 1; i<S.length(); i++) {
        if ((S[i]-'A') <= (S[i-1]-'A')) {
            cnt++; // 알파벳 순서가 줄면 필요
        }
    }

    cout << cnt << '\n';
    return 0;
}

