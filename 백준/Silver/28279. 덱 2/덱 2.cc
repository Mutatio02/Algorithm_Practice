#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    deque<int> deq;
    while(N--) {
        int order;
        cin >> order;
        if(order == 1) {
            int X;
            cin >> X;
            deq.push_front(X);
        }
        else if(order == 2) {
            int X;
            cin >> X;
            deq.push_back(X);
        }
        else if(order == 3) {
            if(!deq.empty()) {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if(order == 4) {
            if(!deq.empty()) {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if(order == 5) {
            cout << deq.size() <<'\n';
        }
        else if(order == 6) {
            cout << (deq.empty() ? 1 : 0) << '\n';
        }
        else if(order == 7) {
            if(!deq.empty()) {
                cout << deq.front() <<'\n';
            }
            else {
                cout << -1 <<'\n';
            }
        }
        else if(order == 8) {
            if(!deq.empty()) {
                cout << deq.back() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}
