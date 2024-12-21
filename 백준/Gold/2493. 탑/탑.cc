#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    stack<pair<int,int>> tower;

    for(int i=1; i<=N; i++) {
        int height;
        cin >> height;
        
        while(!tower.empty()) {
            if(tower.top().first>height) {
                cout << tower.top().second << ' ';
                break;
            }
            tower.pop();
        }
        if(tower.empty()) 
           cout << 0 << ' '; 
        
        tower.push({height,i});
    }
    
    return 0;
}
