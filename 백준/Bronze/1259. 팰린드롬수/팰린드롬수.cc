#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    
    while (true) {
        cin >> str;
        
        if (str == "0") {
            break;
        }

        string compare= str;
        reverse(compare.begin(), compare.end());  

        if (str == compare) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }

    return 0;
}
