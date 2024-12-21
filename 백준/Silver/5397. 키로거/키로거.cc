#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        deque<char> dq;
        string L;
        cin >> L;
        
        auto cursor = dq.begin();

        for(char ch: L) {
            if(ch == '<') {
                if(cursor!= dq.begin()) {
                    cursor--;
                }
            }
            else if(ch == '>') {
                if(cursor!=dq.end()) {
                    cursor++;
                }
            }
            else if(ch =='-') {
                if(cursor!= dq.begin()) {
                    cursor--;
                    cursor = dq.erase(cursor);
                }
            }
            else {
                cursor = dq.insert(cursor,ch); // 커서의 위치에 삽입
                cursor++;
            }
        }
        
        for(auto c: dq) {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}
