#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[9][9] = {0};

    for(int i=0; i<9; i++) {
        for(int j= 0; j<9; j++) {
            cin >> arr[i][j];
        }
    }

    int big = 0;
    int row = 0;
    int col = 0;

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(arr[i][j] > big) {
                big = arr[i][j];
                row = i;
                col = j;
            }
        }
    }

    cout << big << '\n';
    cout << row+1 << " " << col+1;

    return 0;
}
