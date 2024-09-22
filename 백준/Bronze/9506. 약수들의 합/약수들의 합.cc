#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (true) {
        cin >> N;
        if (N == -1) break;

        vector<int> v;
        int sum = 0;

        // 약수 찾기
        for (int i = 1; i < N; i++) {
            if (N % i == 0) {
                v.push_back(i);
                sum += i;
            }
        }

        if (sum == N) {
            cout << N << " =";
            for (size_t i = 0; i < v.size(); i++) {
                if (i > 0) cout << " +";
                cout << " " << v[i];
            }
            cout << '\n';
        } else {
            cout << N << " is NOT perfect.\n";
        }
    }

    return 0;
}
