#include <bits/stdc++.h>
using namespace std;

// 25.02.23 용액 (이분탐색) --> 투포인터?
int N;
vector<long long> v;
long long first,second = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        long long water;
        cin >> water;
        v.push_back(water);
    }        
    sort(v.begin(),v.end());

    int start = 0; // 시작점
    int end = N-1; // 끝점
    long long sum = LONG_LONG_MAX; // 임의의 최대

    while(start<end) {
        long long tmp = v[start]+v[end]; // 양 쪽 끝에서 부터의 합

        if(abs(tmp) < abs(sum)) { // 범위 줄여나가기
            sum = tmp;
            first = v[start];
            second = v[end];
        }

        if(tmp>0) end--; // 양수면 더 작은 수를 더하기 위해 위에서 부터 인덱스 줄여나가기
        else start++; // 반대로 인덱스 늘리기
    }

    cout << first << ' ' << second;

    return 0;
}
