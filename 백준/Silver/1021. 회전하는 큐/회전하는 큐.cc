#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M; // 크기 및 포함되어 있는 수, 뽑을 개수
    deque<int> dq;
    int cnt = 0;
    
    for(int i=1; i<=N; i++) {
        dq.push_back(i);
    }

    while(M--) {
        int num;
        cin >> num;

        int idx = 0;
        for(int i=0; i<dq.size(); i++) {
            if(dq[i] == num) {
                idx = i;
                break;
            }
        }

        if(idx < dq.size()-idx) { // 2번 연산이 최소인 경우
            while(dq.front()!=num) { // 맨 앞이 입력된 수가 아닐때 까지
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        else { // 3번 연산이 최소인 경우
            while(dq.front() != num) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        dq.pop_front(); // 맨 앞의 원소는 제거
        
    }
    cout << cnt;
    return 0;
}
