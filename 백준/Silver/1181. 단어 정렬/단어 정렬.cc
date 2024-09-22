#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

bool my_sort(string& a, string& b) {
    if(a.length()== b.length()) {
        return a<b;
    }
    return a.length() < b.length();
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    set<string> s;

    string word;
    for(int i=0; i<N; i++) {
        cin >> word;
        s.insert(word);
    }

    vector<string> v(s.begin(),s.end());

    sort(v.begin(),v.end(),my_sort);

    for(auto str : v) {
        cout << str<< '\n';
    }

    return 0;
}
