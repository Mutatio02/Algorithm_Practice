#include <bits/stdc++.h>
using namespace std;

// 25.02.25 수강신청 (해시)
int K,L;
unordered_map<string,int> mp;
bool compare(pair<string,int>&a,pair<string,int>&b) {
    return a.second<b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> L;
    
    for(int i=0; i<L; i++) {
        string number;
        cin >> number;
        mp[number] = i;
    }

    vector<pair<string,int>> ans(mp.begin(),mp.end());
    sort(ans.begin(),ans.end(),compare);

    int size = min(K,(int)ans.size());

    for(int i=0; i<size; i++) {
        cout << ans[i].first << "\n";
    }

    return 0;
}
