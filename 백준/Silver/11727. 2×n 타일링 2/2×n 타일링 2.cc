#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    arr[1] = 1;
    arr[1] = 1;
    arr[2] = 3;
    for(int i=3; i<=N; i++) {
        arr[i] = arr[i-1] + 2*(arr[i-2]);
        arr[i] %= 10007;
    }
    cout << arr[N];
    
    return 0;
}
