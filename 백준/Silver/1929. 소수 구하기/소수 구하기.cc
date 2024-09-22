#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPrime(long long num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long M,N;
    cin >> M >> N;
    vector<long long> v;

    for(long long i = M; i<=N; i++) {
        if(isPrime(i)) {
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());

    for(auto num : v) {
        cout << num << '\n';
    }

    return 0;
}
