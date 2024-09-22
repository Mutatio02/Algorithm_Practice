#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string str;
    stack <int> stk;
    while(N--) {
        cin >> str;
        int X;
        if(str== "push") {
            cin >> X;
            stk.push(X);
        }
        else if(str == "pop" ) {
            if(!stk.empty()) {
                cout << stk.top() << '\n';
                stk.pop();
            }
            else {
                cout << "-1\n";
            }
        }
        else if(str == "size") {
            cout << stk.size() << '\n';
        }
        else if(str == "empty") {
            if(stk.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if(str == "top") {
            if(stk.empty()) {
                cout << "-1\n";
            }
            else {
                cout << stk.top() << '\n';
            }
        }
    }
    return 0;
}
