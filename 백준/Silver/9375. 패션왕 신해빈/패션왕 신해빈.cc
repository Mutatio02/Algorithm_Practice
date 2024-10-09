#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        map<string,int> mp; // 의상 종류 및 개수
        for(int i=0; i<n; i++) {
            string s1,s2; // 의상이름및 의상 종류
            cin >> s1 >> s2;
            mp[s2]++; // 의상 종류만 관심 있음
        }

        int result = 1;
        for(auto k : mp) { 
            result *= (k.second+1); // 의상을 입지 않은경우 고려
        }
        result -= 1; // 둘다 안입은 경우제외
        cout << result << '\n';

    }
    return 0;
}
