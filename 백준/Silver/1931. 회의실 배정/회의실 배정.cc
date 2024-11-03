#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N; // 회의 개수
    vector<pair<int,int>> v(N);

    for(int i=0; i<N; i++) {
        int start,end;
        cin >> start >> end;
        v[i] = {end,start}; // 졍렬을 위해 종료시간 기준먼저
    }
    sort(v.begin(),v.end());

    int cnt = 0;
    int last_time = 0;

    for (const auto& meet : v) {
        int start = meet.second;
        int end = meet.first;

        if(start>=last_time) {
            cnt++;
            last_time = end;
        }
    }

    cout << cnt;
    
    return 0;
}
