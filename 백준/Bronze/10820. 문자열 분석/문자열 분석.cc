#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;

    while(getline(cin,str)) {
        int arr[4] = {0}; // 소문자 대문자 숫자 공백
        for(int i=0; i<str.length(); i++) {
            if(str[i] >='a'&& str[i] <='z') {
                arr[0]++;
            }
            else if(str[i] >='A'&& str[i] <='Z') {
                arr[1]++;
            }
            else if(str[i] >='0'&& str[i] <='9') {
                arr[2]++;
            }
            else if(str[i] == ' ') {
                arr[3]++;
            }
        }
        
        for(int i=0; i<4; i++) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}
