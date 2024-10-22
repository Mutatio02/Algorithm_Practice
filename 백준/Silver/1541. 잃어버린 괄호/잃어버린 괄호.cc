#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    string tmp;
    bool isFlag = false;
    int result = 0;

    for(int i=0; i<=str.length(); i++) {
        if(str[i] == '+' || str[i] == '-' || i == str.length()) { // 맨 마지막 혹은 기호의 경우 
            if(isFlag) { // 지금까지 나왔던 값들을 빼주기
                result -= stoi(tmp);
                tmp = "";
            }
            else { // 뺼샘 이외는 더하기
                result += stoi(tmp);
                tmp="";
            }
            
            if(str[i] == '-') // -는 Flag를 이용
                isFlag = true;
        }
        else { // 숫자는 더해서 추가하기
            tmp += str[i];
        }
    }
    cout << result;
    return 0;
}
