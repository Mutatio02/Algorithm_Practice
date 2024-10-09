#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int arr[10] ={0}; // 0~9는 한 세트
    int result = 0;

    while(N>0) {
        arr[N%10]++; 
        N/=10;
    }

    for(int i=0; i<10; i++) {
        if(i==6|| i ==9)    continue; // 6과 9는 일단 무시
        result = max(result,arr[i]); // 세트단위로 계산하므로 최대 값이 세트
    }

    result = max(result,(arr[6]+arr[9]+1)/2); // 6과 9의 계산을 따로 처리

    cout << result;
    
    return 0;
}
