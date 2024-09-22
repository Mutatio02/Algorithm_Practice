#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin >> N >> K;
    queue<int> que;
    vector<int> v;

    for(int i=1; i<=N; i++) {
        que.push(i);
    }
    
    while(!que.empty()) {
        for(int i=1; i<K; i++) {
            que.push(que.front());
            que.pop();
        }
        v.push_back(que.front());
        que.pop();
    }
    
    cout << "<";
    for(int i=0; i<v.size(); i++) {
        if(i == v.size()-1) {
            cout << v[i];
        }
        else {
            cout << v[i] << ", ";
        }
    }
    cout << ">";

    return 0;
}
