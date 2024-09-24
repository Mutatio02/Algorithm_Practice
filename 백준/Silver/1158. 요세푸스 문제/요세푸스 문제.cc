#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin >> N >> K;

    queue<int> que;
    vector<int> v; // 큐에서 나온 요세푸스 순열
    for(int i=1; i<=N; i++) {
        que.push(i);
    }
    while(!que.empty()) {
        for(int i=0; i<K-1; i++) {
            que.push(que.front());
            que.pop();
        }
        v.push_back(que.front());
        que.pop();
    }
    cout << "<";
    for(int i=0; i<v.size(); i++) {
        cout << v[i];
        if(i !=v.size()-1) { // 마지막 인덱스가 아닐떄 까지
            cout << ", ";
        }
    }
    cout << ">";
    
    return 0;
}
