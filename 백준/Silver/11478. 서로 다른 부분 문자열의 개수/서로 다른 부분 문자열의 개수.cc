#include <iostream>
#include <string>
#include <set>

using namespace std;

string s;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s;
    int res = 0;
    int len = s.length();
    for(int i = 1; i <= len; i++) {
        set<string> sub;
        for(int j = 0; j <= len - i; j++) {
            sub.insert(s.substr(j, i));
        }
        res += sub.size();
    }
    cout << res;
}