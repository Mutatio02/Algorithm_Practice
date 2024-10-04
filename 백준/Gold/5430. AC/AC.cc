#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T; // 테스트 케이스 개수

    while(T--) {
        string P; // 함수
        cin >> P;
        int n; // 배열에 들어 있는 수
        cin >> n;
        string order; // 배열에 들어있는 정수
        cin >> order;
        deque<int> dq;

        string temp = "";

        for (int i = 0; i < order.length(); i++) {
            if (order[i] >= '0' && order[i] <= '9') {
                temp += order[i];
            } else if (order[i] == ',' || order[i] == ']') {
                if (!temp.empty()) {
                    dq.push_back(stoi(temp)); // 파싱한 숫자를 덱에 추가
                    temp = ""; // 임시 변수 초기화
                }
            }
        }
        bool R_Flag = false; // reverse 
        bool E_Flag = false; // error

        for(int i=0; i<P.length(); i++) {
            if(P[i] == 'R') {
                R_Flag = !R_Flag;
            }
            else if(P[i] == 'D'){
                if(dq.empty()) {
                    cout << "error\n";
                    E_Flag = true;
                    break;
                }
                else {
                    if(!R_Flag) { // 뒤집혀 있지 않으면
                        dq.pop_front(); // 앞에서
                    }
                    else { // 뒤집혀 있으면 
                        dq.pop_back(); // 뒤에서
                    }
                }
            }
        }

        if(!E_Flag) {
            cout << '[';
            if(!R_Flag) { // 안 뒤집혀 있으면
                for(int i=0; i<dq.size(); i++) { // 그대로
                    cout << dq[i];
                    if(i !=dq.size()-1) {
                        cout << ',';
                    }   
                }
            }
            else { // 뒤집혀 있으면
                for(int i = dq.size()-1; i>=0; i--) { // 뒤집어서
                    cout << dq[i];
                    if(i != 0) {
                        cout << ',';
                    }
                }
            }
            cout << "]\n";
        }
        
    }

    return 0;
}
