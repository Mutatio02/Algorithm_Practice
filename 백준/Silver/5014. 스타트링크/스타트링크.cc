#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int visit[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int F,S,G,U,D;
    cin >> F >> S >> G >> U >> D; // 건물, 현재위치, 이동층, 위로이동, 아래이동
    queue<int> q;
    
    for(int i=1; i<=F; i++) {
        visit[i] = -1;
    }
    q.push(S);
    visit[S] = 0;

    while(!q.empty()) {
        int cur = q.front(); // 현재 위치
        q.pop();
        
        for(auto dir : {cur+U,cur-D}) { // 현재로 부터 위, 아래
            if(dir<=0 || dir > F) continue;
            if(visit[dir] != -1) continue; 
            visit[dir] = visit[cur] +1;
            q.push(dir);
        }
    }
    if(visit[G] == -1) {
        cout << "use the stairs";
    }
    else {
        cout << visit[G];
    }
    
    return 0;
}
