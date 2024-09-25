#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    getline(cin,S);

    string S2;
    for(int i=0; i<S.length(); i++) {
        if(isupper(S[i])) {
            S2 += (S[i]-'A'+ 13) % 26 + 'A'; 
        }
        else if(islower(S[i])) {
            S2 += (S[i] - 'a' + 13) % 26 + 'a';
        }
        else {
            S2 += S[i];
        }
    }
    cout << S2;

    return 0;
}
