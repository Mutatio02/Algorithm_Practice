#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    cin >> X;

    int line = 1;

    while(X>line) {
        X -= line;
        line++;
    }

    if(line%2 == 0) {
        cout << X << "/" << line-X+1;
    }
    else {
        cout << line-X+1 << "/" << X;
    }
    // 홀수 대각선 상승 -- 분자 감소, 분모 증가

    // 짝수 대각선 하강 -- 분자 증가, 분모 감소
    
    return 0;

}
