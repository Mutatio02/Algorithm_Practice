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
        mp.insert({str,true});
    }

    string input;
    int count = 0;
    for(int i=0; i<M; i++) {
        cin >> input;
        if(mp[input]) {
            count++;
        }
    }
    
    cout << count;
    
    return 0;
}