#include <iostream>
#include <algorithm>
using namespace std;

int dp[16][2]; // 상담 기간과 소득을 저장할 배열
int arr[16];   // 각 날짜별 최대 소득을 저장할 배열

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> dp[i][0] >> dp[i][1]; // 상담 소요 기간과 수익 
    }

    for (int i = 1; i <= N; i++) {
        arr[i] = max(arr[i], arr[i - 1]);

        int day = i + dp[i][0]; // 상담 종료 날짜 계산
        if (day <= N + 1) {
            arr[day] = max(arr[day], arr[i] + dp[i][1]);
        }
    }

    int result = max(arr[N], arr[N + 1]);
    cout << result;
    return 0;
}
