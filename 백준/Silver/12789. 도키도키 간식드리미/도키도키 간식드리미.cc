#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int input = 0;
    int cnt = 1; // 순번
    stack<int> stk;
    while(N--) {
        cin >> input;

        if(input == cnt) // 순번과 일치할 경우
            cnt++;
        else { // 순번과 일치하지 않는경우
            stk.push(input);
        }

        while(!stk.empty()&& stk.top() == cnt) { // 스택의 맨 위가 받는순서일때 까지
            stk.pop();
            cnt++;
        }

    }
    if(stk.empty()) {
        cout << "Nice";
    }
    else {
        cout << "Sad";
    }
    
    return 0;
}
