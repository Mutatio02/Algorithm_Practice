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

    string str;
    cin >> str;

    int time[] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

    int sum = 0;
    for(int i=0; str[i]!='\0'; i++) {
        sum += time[str[i] -'A'];
    }
    cout << sum;
    return 0;
}
