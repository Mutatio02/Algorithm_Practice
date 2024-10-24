#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    priority_queue<int,vector<int>,greater<int>> que;

    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        
        if(x>0) {
            que.push(x);
        }
        else if(x==0) {
            if(que.empty()) cout << 0 << '\n';
            else {
                cout << que.top() << '\n';
                que.pop();
            }  
        }
    }

   
    return 0;
}
