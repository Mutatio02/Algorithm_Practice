#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    cin.ignore();

    while(T--) {
        stack<char> stk;
        string str;
        getline(cin,str);
        str += ' ';
        for(int i=0;i<str.length(); i++) {
            if(str[i]== ' ') { // 띄어쓰기를 만나면 스택에 넣어있던 글자 출력
                while(!stk.empty()) {
                    cout << stk.top();
                    stk.pop();
                }
                cout << str[i]; // 띄어 쓰기 입력
            }
            else {
                stk.push(str[i]);
            }
        }
        cout << '\n';
    }
    return 0;
}
