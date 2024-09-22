#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string name;
    string join;
    unordered_map<string,bool> mp;
    vector<string> result;
    for(int i=0; i<N; i++) {
        cin >> name >> join;

        if(join == "leave") {
            mp[name] = false;
        }
        else if(join == "enter") {
            mp[name] = true;
        }
    }

    for(auto& itr: mp) {
        if(itr.second == true) {
            result.push_back(itr.first);
        }
    }

    sort(result.begin(),result.end(),greater<string>());

    for(string& answer: result) {
        cout << answer << '\n';
    }
    
    return 0;
}