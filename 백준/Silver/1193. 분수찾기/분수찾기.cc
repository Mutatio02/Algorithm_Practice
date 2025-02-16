#include <bits/stdc++.h>
using namespace std;

// 25.02.16 분수찾기 복습(수학) 
long long X;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X;

    int line = 1;
    while(X>line) {
        X-=line;
        line++;
    }

    if(line%2==1) cout << line+1-X << "/" << X; 
    else cout << X << "/" << line+1-X;

    // 1부터 N까지의 합 구하기
    // 짝수 줄은 분모 감소 분자 증가
    // 홀수 줄은 붐모 증가 분자 감소
    return 0;
}
