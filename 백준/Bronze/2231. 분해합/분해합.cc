#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i=1; i<N; i++) {
        int sum = i;
        int temp = i;

        while(temp!=0) {
            sum += temp%10; //  1의 자리
            temp = temp/10; // 다음 자리 수를 구하기 위해 나눔
        }

        if(N == sum) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
   
    return 0;
}
