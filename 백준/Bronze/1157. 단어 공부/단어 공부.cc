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
    int count[26] = {0};
    for(int i=0; i<str.length(); i++) {
        if(str[i] >='a' && str[i] <='z') {
            str[i] = str[i] - 'a' + 'A'; // 소문자를 대문자로 변환
        }
        count[str[i]-'A']++;
    }


    int max_cnt = 0;
    char answer = '?';

    for(int i=0; i<26; i++) {
        if(count[i] > max_cnt) {
            max_cnt = count[i];
            answer = 'A' + i;
        }
        else if(count[i]==max_cnt) {
            answer = '?';
        }
    }
    cout << answer;

    return 0;
}
