#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        string S;
        int R;
        cin >> R >> S;

        for(int j=0; j<S.length(); j++) {
            for(int k=0; k<R; k++) {
                cout << S[j];
            }
        }
        cout << "\n";
    }   
    return 0;
}
