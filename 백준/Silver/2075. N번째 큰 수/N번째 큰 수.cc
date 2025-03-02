#include <bits/stdc++.h>
using namespace std;

// 25.03.02 N번쨰 큰 수 (우선순위 큐)
int N;
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int x;
            cin >> x;
            pq.push(x);
            if(pq.size()>N)  {
                pq.pop();
            }
        }
    }   
    
    cout << pq.top();

    return 0;
}
