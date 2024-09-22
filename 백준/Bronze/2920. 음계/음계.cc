#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[8];
    bool isAscending = true;
    bool isDescending = true;
    
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    
    for (int i = 0; i < 7; i++) {
        if (arr[i] < arr[i + 1]) {
            isDescending = false;  
        }
        if (arr[i] > arr[i + 1]) {
            isAscending = false;  
        }
    }

    
    if (isAscending) {
        cout << "ascending";
    } else if (isDescending) {
        cout << "descending";
    } else {
        cout << "mixed";
    }

    return 0;
}
