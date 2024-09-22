#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;
    set<int> st;

    while(M--) {
        string order;
        cin >> order;
        if(order == "add") {
            int x;
            cin >> x;
            if(st.find(x) !=st.end()) {
                continue;
            }
            else {
                st.insert(x);
            }
        }
        else if(order == "remove") {
            int x;
            cin >> x;
            if(st.find(x)==st.end()) {
                continue;
            }
            else {
                st.erase(x);
            }
        }
        else if(order == "check") {
            int x;
            cin >> x;
            if(st.find(x) !=st.end()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if(order == "toggle") {
            int x;
            cin >> x;
            if(st.find(x) !=st.end()) {
                st.erase(x);
            }
            else {
                st.insert(x);
            }
        }
        else if(order == "all") {
            for(int i=1; i<=20; i++) {
                st.insert(i);
            }
        }
        else if(order == "empty") {
            st.clear();
        }
    }

    return 0;
}
