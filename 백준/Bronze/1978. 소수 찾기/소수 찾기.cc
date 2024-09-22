#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int number;
    int answer = 0; // 최종 답
    int count = 0; // 약수의 개수 -->2가 되면 answer를 증가

    while(N--) {
        cin >> number;

        for(int i = 1; i<=number; i++) {
            if(number%i == 0) {
                count++;
            }
        }

        if(count == 2) {
            answer++;
        }

        count = 0;

    }

    cout << answer;

    return 0;
}
