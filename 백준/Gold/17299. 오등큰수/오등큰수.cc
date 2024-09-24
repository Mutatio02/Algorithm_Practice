#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N,0);
    vector<int> NGF(N,-1);
    unordered_map<int,int> mp; // 입력한 수 등장횟수

    for(int i=0; i<N; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }

    stack<int> stk;
    for(int i=0; i<N; i++) {
        while(!stk.empty()&& mp[v[stk.top()]] < mp[v[i]]) { // 숫자를 비교하는 것이 아닌 등장횟수를 비교
            NGF[stk.top()] = v[i];
            stk.pop();
        }

        stk.push(i); // 인덱스 삽입
    }

    for(int n : NGF) {
        cout << n << " ";
    }

    
    return 0;
}
