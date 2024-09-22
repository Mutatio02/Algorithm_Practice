    #include <iostream>
    #include <string>
    #include <vector>
    #include <cmath>
    using namespace std;

    int main(void) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int A,B,C;
        cin >> A >> B >> C;
        int arr[10] = {0}; // 0 1 2 3 의 개수가 저장되는 배열
        
        string str = to_string(A*B*C);
        for(int i=0; i<str.length(); i++) {
            arr[str[i]- '0']++;
        }
        
        for(int i=0; i<10; i++) {
            cout << arr[i] << '\n';
        }
        return 0;
    }