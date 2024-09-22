#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    
    float grade;

    if (str == "A+") {
        grade = 4.3;
    }
    else if (str == "A0") {
        grade = 4.0;
    }
    else if (str == "A-") {
        grade = 3.7;
    }
    else if (str == "B+") {
        grade = 3.3;
    }
    else if (str == "B0") {
        grade = 3.0;
    }
    else if (str == "B-") {
        grade = 2.7;
    }
    else if (str == "C+") {
        grade = 2.3;
    }
    else if (str == "C0") {
        grade = 2.0;
    }
    else if (str == "C-") {
        grade = 1.7;
    }
    else if (str == "D+") {
        grade = 1.3;
    }
    else if (str == "D0") {
        grade = 1.0;
    }
    else if (str == "D-") {
        grade = 0.7;
    }
    else if (str == "F") {
        grade = 0.0;
    }

    cout << fixed<< setprecision(1) <<grade;
    return 0;
}
