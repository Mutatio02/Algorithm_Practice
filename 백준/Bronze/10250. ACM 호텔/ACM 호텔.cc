#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int H,W,N;
    while(T--) { 
        cin >> H >> W >> N;
        int room = 0;
        if(N%H ==0) {
            room = H;
            room *= 100;
            room += N/H;
        }
        else {
            room = N%H;
            room *= 100;
            room += N/H + 1;
        }
        cout << room << '\n';
    }
    // 몇층인지--> N%H, 몇번쨰 룸인지 N%H+1 
    return 0;
}
