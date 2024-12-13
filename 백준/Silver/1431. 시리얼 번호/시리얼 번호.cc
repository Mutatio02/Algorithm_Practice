#include <bits/stdc++.h>
using namespace std;
vector<string> v;

bool compare(string& a, string& b) {
    int lenA = a.length();
    int lenB = b.length();
    int cntA = 0;
    int cntB = 0;

    if(lenA != lenB) return lenA < lenB; // 길이가 작은것이 먼저

    for(int i=0; i<lenA; i++) {
        if(isdigit(a[i])) {
            cntA += a[i] -'0';
        }
    }

    for(int j=0; j<lenB; j++) {
        if(isdigit(b[j])) {
            cntB += b[j]- '0';
        }
    }

    if(cntA != cntB) {
        return cntA < cntB; // 합이 작은 것이 먼저
    }
    
    return a<b; // 사전순으로 정렬
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string str;
    for(int i=0; i<N; i++) {
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(),v.end(),compare);
    for(auto st : v) {
        cout << st << "\n";
    } 
    return 0;
}
