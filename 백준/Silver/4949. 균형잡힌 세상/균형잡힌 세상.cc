#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str; 
    while (true) {
        getline(cin,str);
        stack<char> stk;
        bool isFlag = true;
        if(str == ".")  break;

        for(char ch: str){
            if(ch == '(' || ch == '[') { 
                stk.push(ch);
            }
            else if(ch ==')') {
                if(!stk.empty() && stk.top() == '(') {
                    stk.pop();
                }
                else {
                    isFlag = false;
                    break;
                }
            }
            else if(ch == ']') {
                if(!stk.empty() && stk.top() == '[') {
                    stk.pop();
                }
                else {
                    isFlag = false;
                    break;
                }
            }
        }
        if(stk.empty() && isFlag) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    return 0;
}
