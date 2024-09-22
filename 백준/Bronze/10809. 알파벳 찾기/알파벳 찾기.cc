#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;
    
    for(char i = 'a'; i <='z'; i++) {
        cout << (int)S.find(i) << ' ';
    }
    return 0;
}
