#include <bits/stdc++.h>
using namespace std;

// 25.02.15 캠핑 (수학) 
int L,P,V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num = 1;
    while(true) {
        cin >> L >> P >> V;
        if(L==0 && P==0 && V==0) break;
        cout << "Case " << num << ": " << L*(V/P) + min(V%P,L) << "\n";
        num++;
    }

    return 0;
}
