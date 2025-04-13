#include <bits/stdc++.h>
using namespace std;

// 25.04.13 중앙값 구하기 (우선순위 큐)
int T,M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--) {
        cin >> M;
        int center = 0;
        center = (M/2) + (M%2);
        priority_queue<int> maxpq; // 최대힙 --> 작거나 같은수 
        priority_queue<int,vector<int>,greater<int>> minpq; // 최소힙 -- > 큰 수
        cout << center << "\n";
        
        for(int i=1; i<=M; i++) {
            int num;
            cin >> num;

            if(maxpq.empty() || maxpq.top()>=num) {
                maxpq.push(num);
            }
            else {
                minpq.push(num);
            }
            
            // 균형 맞추기
            if(maxpq.size()>minpq.size()+1) {
                minpq.push(maxpq.top());
                maxpq.pop();
            }
            else if(minpq.size()>maxpq.size()) {
                maxpq.push(minpq.top());
                minpq.pop();
            }

            if(i%2==1) {
                cout << maxpq.top() << ' ';
            }
        }
        cout << "\n";
        
    }


    return 0;
}
