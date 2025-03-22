#include <bits/stdc++.h>
using namespace std;

// 25.03.22 치킨 TOP N (분할 정복-정렬)
int N,K;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }    
    cin >> K;

    int size = N/2;
    while(size>=1) {
        int newsize = N/size;
        for(int i=0; i<N-1; i+=newsize) {
            sort(v.begin()+i,v.begin()+i+newsize);
        }
        if(size == K) {
            for(int i=0; i<N; i++) {
                cout << v[i] << ' ';
            }
            break;
        }
        size /=2;
    }

    return 0;
}