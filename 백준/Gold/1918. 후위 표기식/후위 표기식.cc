#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    stack<char> stk; // 후위 표기식의 연산자를 삽입

    for(int i=0; i<str.length(); i++) {
        if(isupper(str[i])) { // 피연산자
            cout << str[i];
        }
        else { // 연산자 정의
            if(str[i] == '(') {
                stk.push(str[i]);
            }
            else if(str[i] == ')') {
                while(!stk.empty() && stk.top() != '(') { 
                    cout << stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else if(str[i] == '*' || str[i] == '/') {
                while(!stk.empty()&& (stk.top() == '*' || stk.top() =='/')) { // 곱셈과 나눗셈은 연산자 우선순위로 인해 먼저 
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
            else if(str[i] == '+' || str[i] == '-') {
                while(!stk.empty() && stk.top() != '(') {
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
        }
    }
    while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

    return 0;
}
