#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string N;
    int B;
    cin >> N >> B;
    int result = 0;
    for(int i=0; i<N.length(); i++) {
        if(N[i]>='0' && N[i] <='9'){
            result = result * B + (N[i]-'0');
        }
        else {
            result = result * B + (N[i]-'A'+10);
        }
    }

    cout << result;
    
    return 0;
}
