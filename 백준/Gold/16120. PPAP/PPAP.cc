#include <bits/stdc++.h>
using namespace std;

// 25.04.10 PPAP (스택)
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> stk;
    cin >> str;

    for(char ch: str) {
        stk.push(ch);

        if(stk.size()>=4) {
            char one = stk.top(); stk.pop();
            char two = stk.top(); stk.pop();
            char three = stk.top(); stk.pop();
            char four = stk.top(); stk.pop();

            if(one== 'P' && two =='A' && three == 'P' && four == 'P') {
                stk.push('P');
            }
            else {
                stk.push(four);
                stk.push(three);
                stk.push(two);
                stk.push(one);
            }
        }
    }
    
    if(stk.size()==1 && stk.top() == 'P') cout << "PPAP";
    else cout << "NP";

    
    return 0;
}




