#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int score[301];
int dp[301];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    for(int i=1; i<= N; i++) {
        cin >> score[i];
    }
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    dp[3] = max(score[1] + score[3], score[2] + score[3]); // 1층에서 3층 혹은 2층에서 3층

    for(int i=4; i<=N; i++) {
        dp[i] = max(dp[i-2]+score[i],dp[i-3]+score[i-1] + score[i]);
    }
    cout << dp[N];

    return 0;
}
