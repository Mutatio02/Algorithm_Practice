#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> dq;
    int N;
    cin >> N;
    
    while(N--) {
        string order;
        cin >> order;
        if(order == "push_front") {
            int X;
            cin >> X;
            dq.push_front(X);
        }
        else if(order == "push_back") {
            int X;
            cin >> X;
            dq.push_back(X);
        }
        else if(order == "pop_front") {
            if(!dq.empty()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if(order == "pop_back") {
            if(!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else {
                cout << -1 <<'\n';
            }
        }
        else if(order == "size") {
            cout << dq.size() <<'\n';
        }
        else if(order == "empty") {
            cout << (dq.empty() ? 1 : 0) << '\n';
        }
        else if(order == "front") {
            if(!dq.empty()) {
                cout << dq.front() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if(order == "back") {
            if(!dq.empty()) {
                cout << dq.back() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
    
    
    return 0;
}
