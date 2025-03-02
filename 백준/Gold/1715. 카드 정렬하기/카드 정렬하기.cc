#include <bits/stdc++.h>
using namespace std;

// 25.03.02 카드 정렬하기 (우선순위 큐)
int N;
priority_queue<int,vector<int>,greater<int>> pq;
int arr[100005];
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }
    
    while(pq.size()>1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        int tmp = a+b;
        ans += tmp;
        pq.push(tmp);
    }
    
    cout << ans;
    
    return 0;
}
