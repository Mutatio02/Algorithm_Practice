#include <bits/stdc++.h>
using namespace std;
// 25.08.05 줄세우기
int P;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> P;
    int num = 1;
    while(P--) {
        int T;
        cin >> T;
        vector<int> arr;
        int move = 0;

        for(int i=0; i<20; i++) {
            int h;
            cin >> h;
            
            int j = i;
            while(j>0 && arr[j-1]>h) {
                j--;
            }
            move += i-j;
            arr.insert(arr.begin()+j,h);
        }
        cout << T << " " << move << '\n';
    }
    
    return 0;
}
