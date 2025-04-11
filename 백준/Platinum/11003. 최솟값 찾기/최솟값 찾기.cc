#include <bits/stdc++.h>
using namespace std;

// 25.04.11 최솟값 찾기 (큐)
int N,L;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;
    vector<int> arr(N,0);
    deque<pair<int,int>> dq;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }    
    
    for(int i=0; i<N; i++) {
        if(!dq.empty() && dq.front().first < i-L+1) dq.pop_front();
        while(!dq.empty() && dq.back().second > arr[i]) dq.pop_back();
        
        dq.push_back(make_pair(i,arr[i])); // idx value
        
        cout << dq.front().second << ' ';
    }
    
    return 0;
}




