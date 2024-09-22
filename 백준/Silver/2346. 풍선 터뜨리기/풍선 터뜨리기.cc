#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    deque<pair<int,int>> deq;
    int number;
    for(int i=0; i<N; i++) {
        cin >> number;
        deq.push_back(make_pair(i+1,number)); // 순서- 입력값
    }

    while(!deq.empty()) {
        int tmp = deq.front().second;
        cout << deq.front().first << " ";
        deq.pop_front();

        if(deq.empty())     break;

        if(tmp>0) {
            for(int i=0; i<tmp-1; i++) {
                deq.push_back(deq.front());
                deq.pop_front();
            }
        }
        else {
            for(int i=0; i<-tmp; i++) {
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
    return 0;
}
