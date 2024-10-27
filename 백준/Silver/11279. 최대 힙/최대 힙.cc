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
    priority_queue<int> que;
    while(N--) {
        int x;
        cin >> x;

        if(x>0) { // 자연수는 삽입
            que.push(x);
        }
        else if(x==0) { // 0이면
            if(que.empty()) { // 비어있으면 0을 출력
                cout << 0 << '\n';
            }
            else {
                cout << que.top() << '\n'; // 우선순위 큐에 의해 가장 큰 값을 출력
                que.pop(); // 제거
            }
        }
    }

    return 0;
}
