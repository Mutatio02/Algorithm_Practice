#include <bits/stdc++.h>
using namespace std;

// 25.02.19 감소하는 수 (수학) 
long long N;
vector<long long> v;
void solve(long long N) {
    queue<long long> q;

    for(int i=0; i<=9; i++) { // 0부터 9까지 수는 감소하는 수
        q.push(i);
        v.push_back(i);
    }

    while(!q.empty()) {
        long long cur = q.front(); 
        int end = cur%10; 
        q.pop();

        for(int i=0; i<end; i++) {  // 넣어져 있는 수보다 작은 수를 만들기 위함 end포함X
            long long num = 10*cur+i;
            q.push(num);
            v.push_back(num);
        }
    }
    sort(v.begin(),v.end()); 

    if(v.size()<=N) cout << -1;
    else cout << v[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    solve(N);


    return 0;
}
