#include <bits/stdc++.h>
using namespace std;

// 25.02.17 30(수학) 
string N;
vector<int> v;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int sum = 0;
    bool zero = false;
    for(char ch : N) {
        int num = ch- '0';
        if(num==0) zero = true;
        sum += num;
        v.push_back(num);
    }

    if(sum%3!=0 || !zero) {
        cout << -1;
        return 0;
    }

    sort(v.rbegin(),v.rend());

    for(int n: v) {
        cout << n;
    }

    return 0;
}
