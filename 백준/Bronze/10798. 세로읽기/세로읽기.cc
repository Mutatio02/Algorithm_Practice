#include <iostream>
using namespace std;

char arr[5][15];

int main() {
    // 입력 받기
    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j][i] != '\0') { 
                cout << arr[j][i];
            }
        }
    }

    return 0;
}
