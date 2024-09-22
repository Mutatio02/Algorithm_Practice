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
    vector<int> v(N);
    deque<int> deq;
    for(int i=0; i<N; i++) {
        cin >> v[i]; // 0이면 큐 1이면 스택
    }
    
    for(int i=0; i<N; i++) {
        int number;
        cin >> number;

        if(v[i] == 0) {
            deq.push_back(number);
        }
    }

    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int c;
        cin >> c;
        deq.push_front(c);
        cout << deq.back() << " ";
        deq.pop_back();
    }
    return 0;
}
