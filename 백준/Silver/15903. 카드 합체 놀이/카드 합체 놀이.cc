#include <bits/stdc++.h>
using namespace std;

// 25.02.13 카드 합체 놀이 (그리디)
int n,m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; // 최소 힙 사용(데이터 타입, 사용자료)
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    while(n--) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while(m--) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }

    long long ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}
