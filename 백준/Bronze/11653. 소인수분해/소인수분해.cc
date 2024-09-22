#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int i = 2;
    while(N>1) {
        if(N%i ==0) {
            cout << i << '\n';
            N /= i;
        }
        else {
            i++;
        }
    }

    return 0;
}
