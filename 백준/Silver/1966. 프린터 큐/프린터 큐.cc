#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int N,M;
        cin >> N >> M; // N운 자료의 개수 M은 궁금한 자료의 위치
        int count = 0;
        queue<pair<int,int>> que;
        priority_queue<int> pq;

        for(int i=0; i<N; i++) {
            int priority; // 중요도
            cin >> priority;
            que.push({i,priority});; // (입력 순서 위치, 중요도)
            pq.push(priority); // 우선순위 큐에 우선 순위 저장
        }
        while(!que.empty()) {
            int index = que.front().first;
            int value = que.front().second;
            que.pop(); //?
            if(pq.top() == value) {
                pq.pop();
                count++;
                if(index == M) {
                    cout << count << '\n';
                    break;
                } 
            }
            else {
                que.push({index,value});
            }
        }
    }

    return 0;
}
