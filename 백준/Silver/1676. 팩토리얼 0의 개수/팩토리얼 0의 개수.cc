#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int count = 0;
    for(int i=5; i<=N; i*=5) {
        count += N/i;
    }

    cout << count;
    return 0;
}
