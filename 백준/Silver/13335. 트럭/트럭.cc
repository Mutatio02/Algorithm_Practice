#include <bits/stdc++.h>
using namespace std;

// 25.01.15 트럭(시뮬레이션)
int n, w, L; // 트럭 개수, 다리 길이, 최대 하중
int cnt = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;

    queue<int> bdge;
    vector<int> a(n,0);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int weight = 0; // 무게
    for(int i=0; i<n; i++) {
        while(true) {
            if(bdge.size() == w) { // w대의 트럭존재시 위에서 부터 탈출
                weight = weight - bdge.front(); 
                bdge.pop(); // 무게 감소 및 제거
            }
            
            if(weight+a[i] <= L) { // 무게 범위에 해당되면
                break;
            }
            bdge.push(0);
            cnt++;
        }
        bdge.push(a[i]);// 무게 추가
        weight += a[i];
        cnt++; 
    }
    cout << cnt + w;
    return 0;
}
