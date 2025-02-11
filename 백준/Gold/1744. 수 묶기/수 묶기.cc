#include <bits/stdc++.h>
using namespace std;
// 25.02.11 수 묶기(그리디)

long long ans;
void greedysort(vector<int> v) {
    while (1 < v.size()) {
        ans += *(v.end() - 1) * *(v.end() - 2);
        v.pop_back();
        v.pop_back();
    }
    if (v.size())
        ans += v[0];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> p, m;
    int N, t;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t == 1) ans++;
        else if (0 < t)
        p.push_back(t);
        else
        m.push_back(t);
    }
    sort(p.begin(), p.end());
    sort(m.begin(), m.end(), greater<>());

    greedysort(p);
    greedysort(m);

    cout << ans;
    return 0;
}