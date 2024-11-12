#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cout << N * (N-1);
    
    return 0;
}
