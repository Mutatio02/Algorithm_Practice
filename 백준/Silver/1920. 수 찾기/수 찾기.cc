#include <bits/stdc++.h>
using namespace std;

// 25.02.20 수 찾기 복습(이분탐색) 
int N,M;
int arr[100001];

int binarysearch(int object) { // 이분탐색 직접 구현
    int start = 0;
    int end = N-1;
    while(start<=end) {
        int mid = (start+end)/2;
        if(arr[mid] < object) {
            start = mid+1;
        }
        else if(arr[mid] > object) {
            end = mid-1;
        }
        else
            return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    sort(arr,arr+N);
    cin >> M;
    while(M--) {
        int num;
        cin >> num;
        cout << binarysearch(num) << "\n";
    }
    return 0;
}
