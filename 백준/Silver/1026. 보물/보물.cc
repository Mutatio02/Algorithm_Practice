#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    int S = 0;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    for(int i=0; i<N; i++) {
        cin >> B[i];
    }
    sort(A.begin(),A.end()); // A는 오름차순 
    sort(B.rbegin(),B.rend()); // B는 내림차순
    for(int i=0; i<N; i++) {
        S += A[i] * B[i]; 
    }

    cout << S;

    return 0;
}
