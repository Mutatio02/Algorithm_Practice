#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    int arr[26] = {0};
    for(int i=0; i<str.length(); i++) {
        arr[str[i]-'a']++;
    }

    for(int i=0; i<26; i++) {
        cout << arr[i] << ' ';
    }


    return 0;
}
