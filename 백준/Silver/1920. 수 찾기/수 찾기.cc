#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    map<int,bool>mp;
    int number;
    for(int i=0; i<N; i++) {
        cin >> number;
        mp[number] = true;
    }
    int M;
    cin >> M;

    for(int i=0; i<M; i++) {
        cin >>number;
        if(mp[number]) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
    return 0;
}
