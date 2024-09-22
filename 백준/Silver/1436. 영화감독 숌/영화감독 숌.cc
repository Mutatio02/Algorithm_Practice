#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int count = 0;
    int number = 666;

    while(true) {
        string title = to_string(number);

        if(title.find("666") != string :: npos) {
            count++;
            if(count == N) {
                break;
            }    
        }
        number++;
    }
    
    cout << number;
    return 0;
}
