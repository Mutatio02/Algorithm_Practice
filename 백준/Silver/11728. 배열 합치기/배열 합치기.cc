#include <bits/stdc++.h>
using namespace std;
// 25.1.31 배열 합치기(정렬 I) 
long long N,M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<long long> a(N,0);
    vector<long long> b(M,0);
    vector<long long> c(N+M,0);

    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    for(int j=0; j<M; j++) {
        cin >> b[j];
    }
    
    int aidx = 0;
    int bidx = 0;

    for(int i=0; i<N+M; i++) {
        if(aidx == N) { // 배열 a에 있는 원소를 모두 채우면
            c[i] = b[bidx++]; // b에 있는 원소 채우기
        }
        else if(bidx == M) { // 배열 b에 있는 원소를 모두 채우면
            c[i] = a[aidx++]; // a에 있는 원소 채우기
        }
        else if(a[aidx]<=b[bidx]) { 
            c[i] = a[aidx++];
        }
        else {
            c[i] = b[bidx++];
        }
    }

    for(int i=0; i<N+M; i++) {
        cout << c[i] <<' ';
    }
    return 0;
}
