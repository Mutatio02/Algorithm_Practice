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
    stack<int> stk;
    vector<int> v(N,0); // 입력 배열
    vector<int> res(N,-1); // 결과 배열
    for(int i=0; i<N; i++) {
        cin >> v[i];
        
        while(!stk.empty() && v[stk.top()] < v[i]) {  // 입력값이 크다면 해당 인덱스를 오큰수로 설정
            res[stk.top()] = v[i]; 
            stk.pop();
        }
        stk.push(i); // 인덱스를 집어 넣기
    }

    for(int n: res) {
        cout << n << ' ';
    }
    return 0;
}
