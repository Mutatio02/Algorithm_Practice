#include <bits/stdc++.h>
using namespace std;

// 25.02.28 보석 도둑 (이진 탐색 트리)
int N,K;
pair<int,int> dia[300005]; // 가격 무게
multiset<int> bag; // 가방무게
long long ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> dia[i].second >> dia[i].first; // 가격 무게로 입력
    }

    sort(dia,dia+N); // 가격순으로 정렬

    while(K--) {
        int C;
        cin >> C;
        bag.insert(C);
    }
    
    for(int i=N-1; i>=0; i--) { // 가격이 높은 순으로 뒤에서 부터 탐색
        int V,M; // 가격 무게
        tie(V,M) = dia[i];

        auto it = bag.lower_bound(M); // 무게가 M 이상인 것중 가장 작은 것 찾기
        if(it == bag.end()) continue; // 못찾으면 무시
        ans += V;
        bag.erase(it); // 해당 무게를 삭제
    }

    cout << ans;

    return 0;
}
