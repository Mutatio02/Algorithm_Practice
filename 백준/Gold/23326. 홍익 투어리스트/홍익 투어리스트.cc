#include <bits/stdc++.h>
using namespace std;

// 25.03.01 홍익 투어리스트 (이진 탐색 트리)
int N,Q;
set<int> st;
int cur = 1; // 현재 구역

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for(int i=1; i<=N; i++) {
        int area;
        cin >> area; // 명소인가 아닌가?
        if(area) { // 명소면
            st.insert(i); // 해당 구역번호 넣기 --> 명소만 들어간다
        }
    }

    while(Q--) {
        int query;
        cin >> query;

        if(query==1) {
            int area;
            cin >> area;
            if(st.find(area)!=st.end()) { // 찾은 경우(명소인 경우)
                st.erase(area); // 명소 삭제
            }
            else st.insert(area); // 명소 추가
        }
        else if(query==2) {
            int x;
            cin >> x;
            cur = (cur-1+x)%N+1; // cur-1로 0based로 바꾸고 mod연산-> 1based로 다시 바꾸기
        }
        else {
            if(st.empty()) { // 비어있으면 -1
                cout << -1 << "\n";
            }
            else {
                auto it = st.lower_bound(cur); // 현재에서 가장 가까운 명소 찾기
                if(it != st.end()) { // 현재위치 이후에 명소가 있다면
                    cout << *it-cur << "\n"; // 찾은 위치 - 현재 위치
                }
                else { // 현재 위치 이전에 명소가 있다면
                    cout << N-cur+*st.begin() << "\n"; // 처음 명소
                }
            }
        }
    }
    
    return 0;
}
