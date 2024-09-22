#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int mod[] = {25,10,5,1};
    int C;
    while(T--) {
        cin >> C;

        for(int i=0; i<4; i++) {
            cout << C/mod[i]<<" ";
            C = C%mod[i];
        }
    }
    return 0;
}
