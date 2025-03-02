#include <bits/stdc++.h>
using namespace std;

// 25.03.02 파일 합치기 3 (우선순위 큐)
int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        int K;
        cin >> K;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        long long ans = 0;
        while(K--) {
            int x;
            cin >> x;
            pq.push(x);
        }
        while(pq.size()>1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            long long tmp = a+b;
            ans += tmp;
            pq.push(tmp);
        }
        cout << ans << "\n";
    }

    return 0;
}
