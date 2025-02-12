#include <bits/stdc++.h>
using namespace std;

// 25.02.12 공주님의 정원 (그리디)
int N;
int cnt = 0;
vector<pair<int,int>> day;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0; i<N; i++) {
        pair<int,int> st,ed;
        cin >> st.first >> st.second >> ed.first >> ed.second;
        day.push_back({st.first*100+st.second,ed.first*100+ed.second});
    }

    int current = 301;
    while(current <1201) {
        int nexttime = current; // 꽃이 지는 시간을 바탕으로 커버 가능한 경우 찾기
        for(int i=0; i<N; i++) {
            if(day[i].first<=current && day[i].second>nexttime) {
                nexttime = day[i].second;
            }
        }
        if(nexttime == current) {
            cout << 0;
            return 0;
        }
        cnt++;
        current = nexttime; // 현재 진행되는 시간은 마지막에 확인되는 끝나는 시간

    }
    
    cout << cnt;
    return 0;
}
