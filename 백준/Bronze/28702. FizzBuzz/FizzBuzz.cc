#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b,c;
    cin >> a >> b >> c;
    int num = 0;

    if(a[3] != 'z') {
        num = stoi(a) + 3;    
    }

    if(b[3] != 'z' ) {
        num = stoi(b) + 2;
    }

    if(c[3] != 'z') {
        num = stoi(c) + 1;
    }

    if(num%3 == 0 && num%5 ==0) {
        cout << "FizzBuzz";
    }
    else if(num%3 == 0) {
        cout << "Fizz";
    }
    else if(num%5 == 0) {
        cout << "Buzz";
    }
    else {
        cout << num;
    }
    
    return 0;
}
