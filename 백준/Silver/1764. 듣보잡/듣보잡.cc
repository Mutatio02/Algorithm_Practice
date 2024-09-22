#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    unordered_map<string,bool> mp;
    string str;
    for(int i=0; i<N; i++) {
        cin >> str;
        mp[str] = true; 
    }

    string search;
    vector<string> result;
        for(int i=0; i<M; i++) {
        cin >> search;
        if(mp.find(search) != mp.end()) { // 찾았을 경우 삽입
            result.push_back(search);
        }
    }
    sort(result.begin(),result.end());

    cout << result.size() << '\n'; // 삽입된 이름들은 듣보잡의 수
    for(const string& name : result) {
        cout << name << '\n';
    }

    return 0;
}