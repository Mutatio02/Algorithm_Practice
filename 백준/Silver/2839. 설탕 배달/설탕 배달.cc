#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    int count = 0;

    while(N>=0) {
        if(N%5 ==0) {
            count+= N/5;
            N/=5;
            cout << count;
            return 0;
        }
        N-=3;
        count++;
    }
    cout << -1;
    return 0;
}
