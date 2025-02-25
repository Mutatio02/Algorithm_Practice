#include <bits/stdc++.h>
using namespace std;

// 25.02.25 소수의 연속합 (투포인터)
int N;
int cnt = 0;
const int MX = 4000005;
vector<bool> prime(MX,true);
vector<int> v;

void setting(int N) {
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=N; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=N; j+=i) {
                prime[j] = false;
            }
        }
    }
    
    for(int i=2; i<=N; i++) {
        if(prime[i]) v.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    setting(N);

    int start = 0;
    int end = 0;
    int sum = 0;
    
    while(end<v.size()) { 
        sum += v[end];

        while(sum>=N) {
            if(sum==N) cnt++;
            sum-=v[start++];
        }
        end++;
    }

    cout << cnt;

    return 0;
}
