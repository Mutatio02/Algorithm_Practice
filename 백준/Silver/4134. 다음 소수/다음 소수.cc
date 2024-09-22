#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (long long int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int T;
    cin >> T;

    while (T--) {
        long long int n;
        cin >> n;
        while (!isPrime(n)) {
            n++;
        }
        cout << n << '\n';
    }

    return 0;
}
