#include <bits/stdc++.h>
using namespace std;

// 25.02.25 패션왕 신예빈 복습 (해시)
int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        unordered_map<string,int> mp;
        while(N--) {
            string name,kind;
            cin >> name >> kind; // 종류만 신경 쓴다
            mp[kind]++;
        }

        int ans = 1;
        for(auto it: mp) {
            ans *= (it.second+1); // 각종류 + 안입는 경우
        }
        ans -=1; // 모두 안입는 경우(여사건)
        cout << ans << "\n";
    }

    return 0;
}
