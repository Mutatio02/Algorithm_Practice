#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> A(10), B(10);

    for(int i=0; i<10; i++) cin >> A[i];
    for(int i=0; i<10; i++) cin >> B[i];

    int A_num = 0;
    int B_num = 0;
    char last_winner = 'D'; // 마지막 승자

    for(int i=0; i<10; i++) {
        if(A[i] > B[i]) {
            A_num += 3;
            last_winner = 'A';
        }
        else if(A[i] == B[i]) {
            A_num += 1;
            B_num += 1;
        }
        else {
            B_num += 3;
            last_winner = 'B';
        }
    }

    cout << A_num << " " << B_num << "\n";

    if(A_num > B_num) cout << 'A';
    else if(A_num < B_num) cout << 'B';
    else cout << last_winner; 

    return 0;
}