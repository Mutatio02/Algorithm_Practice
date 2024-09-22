#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    int size[6];
    for(int i=0; i<6; i++) {
        cin >> size[i];
    }

    int T,P;
    cin >> T >> P;

    int sum = 0;
    int tmp = 0;
    for(int i=0; i<6; i++) {
        if(size[i]%T == 0) {
            tmp = size[i]/T;
        }
        else {
            tmp = size[i]/T + 1;
        }
        sum += tmp;
    }

    // 티셔츠
    cout << sum << '\n';
    // 펜
    cout << N/P << " " << N%P;
    return 0;
}