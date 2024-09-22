#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    stack<int> stk;
    int number;
    while(K--) {
        cin>>number;
        if(stk.empty()) {
            stk.push(number);
        }
        else {
            if(number == 0) {
                stk.pop();
            }
            else {
                stk.push(number);
            }
        }
    }

    int sum = 0;
    while(!stk.empty()) {
        sum +=stk.top();
        stk.pop();
    }
    cout << sum;

    return 0;
}
