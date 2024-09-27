#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v(9,0);
    int sum = 0; // 합이 100
    for(int i=0; i<9; i++) {
        cin >>  v[i];
        sum += v[i];
    }

    sort(v.begin(),v.end());

    for(int i=0; i<8; i++) {
        for(int j=i+1; j<9; j++) {
            if(sum-(v[i]+v[j]) == 100) { // 2개를 제외한게 100이면

                for(int k = 0; k<9; k++) {
                    if(k != i && k != j) { // 해당 2개를 제외하고 출력
                        cout << v[k] << '\n';
                    }
                }
                return 0;
            }
        }
    }


    return 0;
}
