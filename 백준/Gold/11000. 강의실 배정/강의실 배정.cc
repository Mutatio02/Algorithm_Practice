#include <bits/stdc++.h>
using namespace std;

// 25.02.13 강의실 배정 (그리디) -- 우선순위 큐 사용
int N;
priority_queue<int,vector<int>,greater<int>> pq;
vector<pair<int,int>> room;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i=0; i<N; i++) {
        int s,t;
        cin >> s >> t;
        room.push_back({s,t});
    }

    sort(room.begin(),room.end());
    pq.push(room[0].second);

    for(int i=1; i<N; i++) {
        if(room[i].first < pq.top()) {
            pq.push(room[i].second);
        }
        else {
            pq.push(room[i].second);
            pq.pop();
        }
    }

    cout << pq.size();
    
    return 0;
}
