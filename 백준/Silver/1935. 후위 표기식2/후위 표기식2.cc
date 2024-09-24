#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<double> v(N);
    stack<double>stk;

    string str;
    cin >> str;

    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    
    for(int i=0; i<str.length(); i++) {
        if(str[i] >='A' && str[i] <='Z') { // 연산자가 아닌경우
            stk.push(v[str[i]-'A']); // A는 첫번째 B는 두번쨰 ... 
        }
        else { // 연산자 인 경우
            double b = stk.top();   stk.pop(); // 두번째 피연산자
            double a = stk.top();   stk.pop(); // 첫번쨰 피연산자
            
            if(str[i] == '+') {
                stk.push(a+b);
            }
            else if(str[i] == '-') {
                stk.push(a-b);
            }
            else if(str[i] == '*') {
                stk.push(a*b);
            }
            else if(str[i] == '/') {
                stk.push(a/b);
            }
        }
    }

    cout << fixed;
    cout.precision(2); // 소수 2째 자리까지 출력
    cout << stk.top();
    return 0;
}
