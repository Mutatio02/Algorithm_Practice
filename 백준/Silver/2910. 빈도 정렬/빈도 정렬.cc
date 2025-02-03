#include <bits/stdc++.h>
using namespace std;
// 25.2.3 빈도 정렬(정렬 II) 
int N;
long long C;
bool compare(const pair<int,long long> &a, const pair<int,long long> &b) {
    return a.first > b.first;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    vector<pair<int ,long long>> v; // 카운트(cnt), 숫자
    for(int i=0; i<N; i++) {
        long long num;
        cin >> num;

        bool flag = false;
        for(auto& c : v) {
            if(c.second == num) { // 위에 입력한 수가 같으면
                flag = true;
                c.first++; // 카운트 증가
                break;
            }
        }
        if(!flag) v.push_back({1,num});
    }

    stable_sort(v.begin(),v.end(),compare);

    for(auto& q: v) {
        while(q.first--) {
            cout << q.second << ' ';
        }
    }
    
    return 0;
}
