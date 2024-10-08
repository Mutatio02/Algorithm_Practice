#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int cnt = 0;
    while(N--) {
        string str;
        cin >> str;
        stack<char> stk; // 문자를 넣는 스택

        for(char ch: str) {
            if(!stk.empty() && stk.top() == ch) { // 스택의 맨위와 글자가 쌍이 맞으면 스택을 비운다
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        if(stk.empty()) cnt++; // 스택이 빈 상태는 쌍이 맞은 상태이기 떄문에 증가한다.
    }
    cout << cnt;
    return 0;
}
