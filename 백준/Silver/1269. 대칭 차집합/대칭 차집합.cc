#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin >> a >> b;
    set<int> st;
    int number;
    for(int i=0; i<a+b; i++) { // a와b의 횟수만큼 삽입 set이라 중복된 원소는 사라짐
        cin >> number;
        st.insert(number);
    }

    int S = st.size(); // 전체 집합
    int C = a+b-S; // 교집합

    cout << S-C;

    return 0;
}