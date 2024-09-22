#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v(N);
    int arr[8001] ={0};
    int sum,avg,center,big,range;

    for(int i=0; i<N; i++) {
        cin >> v[i];
        sum += v[i];
        arr[v[i]+4000]++;
    }

    sort(v.begin(),v.end());

    int cnt = 0;
    vector<int> count;
    for(int i=0; i<8001; i++) {
        if(arr[i] >cnt) {
            cnt = arr[i];
            count.clear();
            count.push_back(i-4000);
        }
        else if(arr[i] == cnt) {
            count.push_back(i-4000);
        }
    }
    avg = round((double)sum/N);
    center = v[N/2];
    if(count.size() >1) {
        big = count[1];
    }
    else {
        big = count[0];
    }
    range = v.back() - v.front();

    cout << avg << '\n';     // 산술 평균
    cout << center << '\n';  // 중앙값
    cout << big << '\n';     // 최빈값
    cout << range << '\n';   // 범위
    
    return 0;
}
