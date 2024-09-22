#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,M;
    cin >> N >> M;
    
    map<string,string> mp; // key-value 컨테이너 map 사용
    for(int i=0; i<N; i++) {
        string address, password;
        cin >> address >> password;
        mp[address] = password;
    }

    for(int i=0; i<M; i++) {
        string find;
        cin >> find;
        cout << mp[find] << '\n';
    }
    return 0;
}
