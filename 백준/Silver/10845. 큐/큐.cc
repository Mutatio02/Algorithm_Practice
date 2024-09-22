#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string str;
    queue <int> que;
    while(N--) {
        cin >> str;
        int X;
        if(str== "push") {
            cin >> X;
            que.push(X);
        }
        else if(str == "pop" ) {
            if(!que.empty()) {
                cout << que.front() << '\n';
                que.pop();
            }
            else {
                cout << "-1\n";
            }
        }
        else if(str == "size") {
            cout << que.size() << '\n';
        }
        else if(str == "empty") {
            if(que.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if(str == "front") {
            if(que.empty()) {
                cout << "-1\n";
            }
            else {
                cout << que.front() << '\n';
            }
        }
        else if(str == "back") {
            if(que.empty()) {
                cout << "-1\n";
            }
            else {
                cout << que.back() << '\n';
            }
        }
    }
    return 0;
}
