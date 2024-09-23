#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[1000001];
    int N;
    cin >> N;
    
    for(int i=2; i<=N; i++) {
        arr[i] = arr[i-1] + 1; // arr[1] = 0, 경우의 수가 여러개 발생 가능하므로 가능한 최소값으로 설정
        
        if(i%2 == 0) { // 2로 나누어 떨어지는 경우 arr[i] = arr[i/2] + 1 
            arr[i] = min(arr[i], arr[i/2] + 1);
        }

        if(i%3==0) { // 3로 나누어 떨어지는 경우 arr[i] = arr[i/3] + 1
            arr[i] = min(arr[i], arr[i/3] + 1);
        }
    }
    
    cout << arr[N];
    return 0;
}
