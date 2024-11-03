#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N; // 돌의 개수
    
    if(N%2 == 1) {
        cout << "SK";
    }
    else {
        cout << "CY";
    }
    
    return 0;
}
