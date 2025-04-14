#include <bits/stdc++.h>
using namespace std;

// 25.04.14 전생했더니 슬라임 연구자였던 건에 대하여 (Hard) (우선순위 큐)
const long long mod = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        priority_queue<long long int,vector<long long int >,greater<long long int >> pq;
        for (int i = 0; i < n; i++) {
            long long int num; cin >> num;
            pq.push(num);
        }
        long long int score = 1;
        while (pq.size() >=2) {
            long long int one = pq.top(); pq.pop();
            long long int two = pq.top(); pq.pop();
            score *= (((one % mod) * (two % mod)) % mod);
            pq.push(one * two);    
            score%=mod;
        }
    cout << score << "\n";
    }

    return 0;
}




