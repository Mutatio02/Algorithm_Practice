#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int E,S,M;
    cin >> E >> S >> M;

    int e=1, s=1, m=1; // 증가 변수
    int year = 1;
    
    while(1) {
        if(e== E && s == S && m == M) {
            break;
        }
        e++;
        s++;
        m++;
        // 범위에 걸리면 1로 초기화
        if(e > 15)
            e = 1;
        if(s > 28)
            s = 1;
        if(m >19)
            m= 1;

        year++;  
    }

    cout << year;
    return 0;
}
