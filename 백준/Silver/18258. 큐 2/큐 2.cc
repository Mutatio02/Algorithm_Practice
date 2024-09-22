#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    queue<int> que;
    while(N--) {
        string order;
        cin >> order;

        if(order =="push") {
            int X;
            cin >> X;
            que.push(X);
        }
        else if(order == "pop") {
            if(!que.empty()) {
                cout << que.front() << '\n';
                que.pop();
            }
            else {
                cout << -1 <<'\n';
            }
        }
        else if(order == "size") {
            cout << que.size() << '\n';
        }
        else if(order == "empty") {
            cout << (que.empty() ? 1 : 0) << '\n';
        }
        else if(order == "front") {
            if(!que.empty()) {
                cout << que.front() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if(order == "back") {
            if(!que.empty()) {
                cout << que.back() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }

    }
    return 0;
}
