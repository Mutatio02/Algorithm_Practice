#include <bits/stdc++.h>
using namespace std;

// 25.02.23 멀티버스 Ⅱ (이분탐색) 
int M,N;
int arr[105][10005];
int ans = 0;
void press(int arr[]) {
    vector<int> v(arr,arr+N);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0; i<N; i++) {
        arr[i] = lower_bound(v.begin(),v.end(),arr[i]) - v.begin();
    }
}
bool compare(int a[],int b[]) {
    for(int i=0; i<N; i++) {
        if(a[i]!=b[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
        press(arr[i]);
    }

    for(int i=0; i<M-1; i++) {
        for(int j=i+1; j<M; j++) {
            ans += compare(arr[i],arr[j]);
        }
    }    

    cout << ans;

    return 0;
}
