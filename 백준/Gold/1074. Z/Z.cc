#include <bits/stdc++.h>
using namespace std;


int visit(int n,int r, int c) {
    if(n == 0) return 0;
    int length = 1<<(n-1); // 길이

    if(r<length && c <length)   
        return visit(n-1,r,c); // 왼쪽 위

    if(r<length && c>= length)
        return length*length + visit(n-1,r,c-length); // 오른쪽 위

    if(r>=length && c<length)
        return length*length*2 + visit(n-1,r-length,c); // 왼쪽 아래

    
    return length*length*3 + visit(n-1,r-length,c-length); // 오른쪽 아래
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,r,c;
    cin >> N >> r >> c;
    cout << visit(N,r,c);

    return 0;
}
