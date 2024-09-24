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
    cin >> S;

    stack<char> stk;
    int cnt = 0;
    for(int i=0; i<S.length(); i++) {
        if(S[i] == '(') {
            stk.push(S[i]);
        }
        else { // ')'인 경우
            if(S[i-1] == '(') { // 즉 '()'인 경우 
                stk.pop(); // 이전에 들어온 '('를 제거
                cnt +=stk.size();
            }
            else {
                cnt+=1;
                stk.pop();
            }
        }
        
    }
    cout << cnt;
    return 0;
}
