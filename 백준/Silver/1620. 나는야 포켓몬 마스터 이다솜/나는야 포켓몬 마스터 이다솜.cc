#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    map<string,int> mp; // 이름 -- 번호
    string arr[100001]; // 번호 -- 이름
    string name;
    for(int i=1; i<=N; i++) {
        cin >> name;
        mp.insert({name,i});
        arr[i] = name;
    }
    
    string problem;
    for(int i=1; i<=M; i++) {
        cin>> problem;
        if(isdigit(problem[0])) { // 번호면
            cout <<arr[stoi(problem)]  << '\n'; // 이름
        }
        else {// 이름이면
            cout<< mp[problem] << '\n'; //번호
        }
    }
    return 0;
}