#include <bits/stdc++.h>
using namespace std;

// 25.02.19 쉽게 푸는 문제 (수학) 
int A,B;
int arr[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    int sum = 0;
    int idx = 1; // 인덱스를 두고 관리 -- > B를 넘지 말기
    for(int i=1; i<=B; i++) {
        for(int j=0; j<i && idx<=B; j++) {
            arr[idx++] = i;
        }
    }

    for(int i=A; i<=B; i++) {
        sum += arr[i];
    }

    cout << sum;
    return 0;
}
