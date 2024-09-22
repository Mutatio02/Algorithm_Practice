#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string str;
        cin >> str;
        stack<char> stk;
        for(int i=0; i<str.length(); i++) {
            if(stk.empty()) {
                stk.push(str[i]);
            }
            else {
                if(stk.top() == '(' && str[i]== ')') {
                    stk.pop();
                }
                else {
                    stk.push(str[i]);
                }
            }
                
        }

        if(!stk.empty()) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }

    }
    return 0;
}
