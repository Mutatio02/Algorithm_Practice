#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    queue<int> que;
    for(int i=1; i<=N; i++){
        que.push(i);
    }

    while(que.size() > 1) {
        que.pop();
        que.push(que.front());
        que.pop();
    }

    cout << que.front();

    return 0;
}
