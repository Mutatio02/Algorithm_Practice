#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    int x,y;

    for(int i=-999; i<=999; i++) {
        for(int j=-999; j<=999; j++) {
            if(a*i + b*j == c && d*i + e*j == f) {
                x= i;
                y= j;
                break;
            }
        }
    }
    cout << x << " " << y;
   
    return 0;
}
