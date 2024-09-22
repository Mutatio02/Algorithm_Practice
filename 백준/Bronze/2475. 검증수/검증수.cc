#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;

    vector<int> v = {a*a,b*b,c*c,d*d,e*e};
    
    long long sum = 0;
    for(int i=0; i<v.size(); i++) {
        sum += v[i];
    }
    cout << sum%10;
    
    return 0;
}