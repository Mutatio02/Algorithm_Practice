#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int cnt = 0;
    for(int i=1; i<=N; i*=10) {
        cnt += N - i + 1; // 각 자리수의 개수를 더하기
    }
    cout << cnt;
    return 0;
}
