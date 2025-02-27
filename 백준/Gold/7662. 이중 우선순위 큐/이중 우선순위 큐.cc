#include <bits/stdc++.h>
using namespace std;

// 25.02.27 이중 우선순위 큐 (이진 탐색 트리)
int T;
int k;

long long calcul(priority_queue<long long>& tmp) {
    long long ans = 0;

    while(!tmp.empty()) {
        ans += tmp.top();
        tmp.pop();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        multiset<int> st; // 중복을 허용하며 순서 정렬된 자료 구조 key값만 관심 있음
        cin >> k;
        while(k--) {
            char ch;
            int n;
            cin >> ch >> n;
            
            if(ch == 'I') st.insert(n);
            else if(!st.empty()) {
                if(n==1) {
                    auto it = prev(st.end()); // 최대값은 끝(end)에서 마지막 원소
                    st.erase(it);
                }
                else if(n==-1) {
                    auto it = st.begin();
                    st.erase(it);
                }
            }
        }
        if(st.empty()) cout << "EMPTY\n";
        else cout << *prev(st.end()) << " " << *st.begin() << "\n";

    }

    return 0;
}
