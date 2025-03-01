#include <bits/stdc++.h>
using namespace std;

// 25.03.01 절댓값 힙 (우선순위 큐)
int N;

class compare{
public:
    bool operator() (int a,int b) {
        if(abs(a)==abs(b)) { // 절대값이 작은 값이 여러개일때는 
            return a>b; // 가장 작은수
        }
        return abs(a)>abs(b); // 절대값이 가장 작은 값 
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N;
    priority_queue<int,vector<int>,compare> pq;
    while(N--) {
        int x;
        cin >> x;

        if(x!=0) {
            pq.push(x);
        } 
        else {
            if(pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }    
    

    return 0;
}
