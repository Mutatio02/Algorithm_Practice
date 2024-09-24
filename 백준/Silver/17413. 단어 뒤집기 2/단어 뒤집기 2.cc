#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    getline(cin,S);
    
    stack<char> stk;
    string result;
    for(int i=0; i<S.length(); i++) {
        if(S[i]=='<') { // '<'를 만나면 스택에 들어있던 것들 출력
            while(!stk.empty()) {
                result+=stk.top();
                stk.pop();
            }
            while(true) { // '>'를 만나기 전까지 그대로 추가
                result += S[i];
                if(S[i] == '>') break;
                i++;
            }
        }
        else if (S[i] == ' ') { //공백을 만나면 스택에 들어있던 것들 출력
            while(!stk.empty()) {
                result+=stk.top();
                stk.pop();
            }
            result += S[i]; //공백 추가
        }
        else {
            stk.push(S[i]);
        }
    }

    while(!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
    
    cout << result;
    return 0;
}
