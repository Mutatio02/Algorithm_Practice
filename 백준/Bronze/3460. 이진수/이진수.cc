#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int poz = 0;
        while(n>0) {
            if(n&1) { // n&1이 참이면 true 0이면 false
                cout << poz << " ";
            }
            n >>= 1; // 2로 나누는 것과 의미가 같은 비트 연산자
            poz++;
        }
    }
    return 0;
}
