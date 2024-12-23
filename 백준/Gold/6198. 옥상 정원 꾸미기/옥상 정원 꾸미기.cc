#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >>N;
    
    stack<int> stk;
    long long cnt = 0;

    for(int i=0; i<N; i++) {
        long long height;
        cin >> height;

        while(!stk.empty() && stk.top() <= height) { // height가 top의 빌딩보다 작을때 관찰 가능능
            stk.pop();
        }
        
        cnt += stk.size();
        stk.push(height);
    }
    
    cout << cnt;
    return 0;
}
