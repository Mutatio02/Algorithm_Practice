#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int B;
    cin >> N >> B;
    string result ="";

    while(N>0) {
        int mod = N%B;
        if(mod>=0 && mod <= 9) {
            result += (char)(mod + '0');
        }
        else {
            result += (char)(mod - 10 + 'A');
        }
        N/=B;
    }

    reverse(result.begin(),result.end());

    cout << result;
    
    return 0;
}
