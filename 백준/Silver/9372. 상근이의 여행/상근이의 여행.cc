#include <bits/stdc++.h>
using namespace std;

// 25.04.08 상근이의 여행 (그래프)
int T,N,M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T--) {
        cin >> N >> M;

        for(int i=0; i<M; i++) {
            int a,b;
            cin >> a >> b;
        }

        cout << N-1 << "\n";
    }
    
    
    return 0;
}




