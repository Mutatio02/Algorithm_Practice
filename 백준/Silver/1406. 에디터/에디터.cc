#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    stack<char> left,right; //왼쪽과 오른쪽을 구분

    int N;
    cin >> N;
    
    for(char ch: str) { // 왼쪽 스택부터 시작
        left.push(ch);
    }
    while(N--) {
        string order;
        cin >> order;

        if(order == "L") { // 커서가 왼쪽으로 가는것은 왼쪽스택에서 오른쪽 스택으로 이동이다.
            if(!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        }
        else if(order == "D") { // 반대로 커서가 오른쪽으로 가는 것은 오른쪽 스택에서 왼쪽 스택으로 이동이다.
            if(!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        }
        else if(order == "B") { // 왼쪽에 있는 문자 삭제는 왼쪽 스택에서 pop이다.
            if(!left.empty()) {
                left.pop();
            }
        }
        else if(order == "P") { // 왼쪽에 있는 문자는 삽입이다.
            char ch;
            cin >> ch;
            left.push(ch);
        }
    }
    // 출력을 위해 왼쪽 스택의 값을 오른쪽으로 이동
    while(!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()) {
        cout << right.top();
        right.pop();
    }
    return 0;
}
