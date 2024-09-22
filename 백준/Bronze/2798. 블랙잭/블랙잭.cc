#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M; //카드 개수, M과 가장 가까운 수
    cin >> N >> M;

    vector<int> v(N); // 입력 받을 배열
    int result = 0; // 결과 

    for(int i=0; i<N; i++) {
        cin >> v[i];
    }

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int k = j+1; k<N; k++) {
                int sum = v[i]+v[j]+v[k];
                if(sum <=M && sum>result) {
                    result = sum;
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}
