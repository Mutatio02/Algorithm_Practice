#include <bits/stdc++.h>
using namespace std;

// 25.02.26 걸그룹 마스터 준석이 (해시)
int N,M;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    unordered_map<string,vector<string>> member;
    unordered_map<string,string> team;
    while(N--) {
        string group;
        int num;
        cin >> group;
        cin >> num;
        for(int i=0; i<num; i++) {
            string person;
            cin >> person;
            member[group].push_back(person);
            team[person] = group;
        }

    }

    while(M--) {
        string pb;
        int select;
        cin >> pb;
        cin >> select;

        if(select==1) {
            cout << team[pb] << "\n";
        }
        else {
            vector<string>& tmp = member[pb];
            sort(tmp.begin(),tmp.end());

            for(auto& name: tmp) {
                cout << name << "\n";
            }
        }
    }
    return 0;
}
