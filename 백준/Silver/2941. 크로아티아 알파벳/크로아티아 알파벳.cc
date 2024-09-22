#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    
    vector<string> alpha = {"c=","c-","dz=","d-","lj","nj","s=","z="};

    for(int i=0; i<alpha.size(); i++) {
        while(str.find(alpha[i])!=string::npos) {
            str.replace(str.find(alpha[i]),alpha[i].size(),"@");
        }
    }
    
    cout << str.length();
    return 0;
}
