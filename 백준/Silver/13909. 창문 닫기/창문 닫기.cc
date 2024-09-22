#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int count = 0;
    for(int i=1; i*i<= N; i++) {
        count++;
    }
    cout << count;
    return 0;
}
