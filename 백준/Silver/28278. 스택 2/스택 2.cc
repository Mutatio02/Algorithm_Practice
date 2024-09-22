#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    stack<int> stk;
    while(N--) {
        int order;
        cin >> order;
        
        if(order == 1) {
            int X;
            cin >> X;
            stk.push(X);
        }
        else if(order == 2) {
            if(!stk.empty()) {
                cout << stk.top() << '\n';
                stk.pop();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if(order == 3) {
            cout << stk.size() << '\n';
        }
        else if(order == 4) {
            cout << (stk.empty() ? 1 : 0) << '\n';
        }
        else if(order == 5) {
            if(!stk.empty()) {
                cout << stk.top() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}
