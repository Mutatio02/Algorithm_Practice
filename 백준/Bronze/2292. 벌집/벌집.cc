#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>> N;

    int room = 1;
    int layer = 1;

    while(N>room) {
        room = room + 6 * layer;
        layer++; 
    }

    cout << layer;
    
    return 0;

}
