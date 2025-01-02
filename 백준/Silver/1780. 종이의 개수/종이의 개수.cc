#include <bits/stdc++.h>
using namespace std;
// 25.01.02  재귀복습
int N;
int paper[2701][2701];
int cnt[3]; // -1(0) 0(1) 1(2)의 개수를 담을 배열
bool check(int a,int b, int size) {
    for(int i=a; i<a+size; i++) {
        for(int j=b; j<b+size; j++) {
            if(paper[a][b]!=paper[i][j])
                return false;
        }
    }
    return true;
}
void solve(int x,int y, int size) {
    if(check(x,y,size)) {
        cnt[paper[x][y]+1] +=1;
        return;
    }
    int newsize = size/3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            solve(x+i * newsize, y+j * newsize, newsize);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0,0,N);

    for(int i=0; i<3; i++) {
        cout << cnt[i] << "\n";
    }
    return 0;
}
