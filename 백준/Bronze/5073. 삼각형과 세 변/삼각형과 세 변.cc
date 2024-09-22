#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;

    while (true) {
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || b + c <= a || a + c <= b) {
            cout << "Invalid\n";
        }
        else if (a == b && b == c) {
            cout << "Equilateral\n";
        }
        else if (a == b || b == c || a == c) {
            cout << "Isosceles\n";
        }
        else {
            cout << "Scalene\n";
        }
    }

    return 0;
}
