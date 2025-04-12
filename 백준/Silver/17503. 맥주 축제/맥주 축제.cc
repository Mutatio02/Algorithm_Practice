#include <bits/stdc++.h>
using namespace std;

// 25.04.12 맥주 축제 (우선순위 큐)
int N,M,K;
vector<pair<int,int>> bear;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    priority_queue<int,vector<int>,greater<int>> pq;

    while(K--) {
        int v,c;
        cin >> v >> c; // 선호도와 도수
        bear.push_back({v,c}); 
    }

    sort(bear.begin(),bear.end(),[](pair<int,int> a, pair<int,int> b) { return a.second<b.second; });
    int ans = -1;
    long long sum = 0;

    for(auto [v,c] : bear) {
        pq.push(v);
        sum += v;
        if(pq.size() > N) {
            sum -= pq.top();
            pq.pop();
        }
        if(pq.size() == N && sum >=M) {
            ans = c;
            break;
        }
    }

    cout << ans;

    return 0;
}




