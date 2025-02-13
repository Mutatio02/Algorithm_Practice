#include <bits/stdc++.h>
using namespace std;

// 25.02.12 뒤집기 (그리디)
string str;
int cnt[2]; // 0의 그룹과 1의 그룹

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    cnt[str[0]-'0']++; // 첫번째 수의 그룹 증가
    for(int i=0; i<str.length()-1; i++) {
        if(str[i] != str[i+1]) { // 같지 않다면 다른 그룹이므로
            cnt[str[i+1]-'0']++;  // 증가
        }
    }
    int ans = min(cnt[0],cnt[1]);
    cout << ans;

    return 0;
}
