#include <bits/stdc++.h>
using namespace std;

// 25.03.03 가운데를 말해요 (우선순위 큐)
int N;
priority_queue<int> l; // 최대 힙 -->top이 중앙값
priority_queue<int,vector<int>,greater<int>> r; // 최소힙 num 보다 큰 값
void solve(int num) {
    if(l.empty()||l.top()>=num) {
        l.push(num);
    }
    else r.push(num);

    if(l.size() > r.size()+1) {
        r.push(l.top());
        l.pop();
    }
    else if(r.size()>l.size()) {
        l.push(r.top());
        r.pop();
    }

    cout << l.top() << "\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--) {
        int n;
        cin >> n;
        solve(n);
    }
    
    return 0;
}
