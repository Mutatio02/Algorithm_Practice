#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vector<int> A(N,0);
    vector<int> B(M,0);
    vector<int> C;
    for(int i=0; i<N; i++) {
        cin >> A[i];
        C.push_back(A[i]);
    }
    
    for(int j=0; j<M; j++) {
        cin >> B[j];
        C.push_back(B[j]);
    }
    
    sort(C.begin(),C.end());

    for(int i=0; i<C.size(); i++) {
        cout << C[i] << " ";
    }
    
    return 0;
}
