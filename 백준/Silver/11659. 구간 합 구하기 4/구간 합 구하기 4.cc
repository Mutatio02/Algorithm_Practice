#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[100001]; // 입력
int sum[100001]; // 누적합 저장 배열
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i]; // 누적합 = 누적합 이전 + 입력값
    }
    while(M--) {
        int start,end;
        cin >> start >> end;
        
        cout << sum[end] - sum[start-1] << '\n'; // 끝 위치의 누적합 - 시작 위치 전의 누적합
    }

    return 0;
}
