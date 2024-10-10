#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string board[51];
int result = 0;
void check(int n) {
    // 가로
    
    for(int i=0; i<n; i++) {
        int cnt =1;
        for(int j =0; j<n-1; j++) {
            if(board[i][j] == board[i][j+1]) { // 같다면 수를 증가
                cnt++;
            }
            else { // 같지 않다면 초기화
                result = max(result,cnt);
                cnt = 1;
            }
        }
        result = max(result,cnt);
    }
    // 세로
    for(int j=0; j<n; j++) {
        int cnt =1;
        for(int i =0; i<n-1; i++) {
            if(board[i][j] == board[i+1][j]) { // 같다면 수를 증가
                cnt++;
            }
            else { // 같지 않다면 초기화
                result = max(result,cnt);
                cnt = 1;
            }
        }
        result = max(result,cnt);
    }
    
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> board[i];
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N-1; j++) {
            swap(board[i][j],board[i][j+1]);
            check(N);
            swap(board[i][j],board[i][j+1]);
        }
    }
    for(int i=0; i<N-1; i++) {
        for(int j=0; j<N; j++) {
            swap(board[i][j],board[i+1][j]);
            check(N);
            swap(board[i][j],board[i+1][j]);
        }
    }
    cout << result;

    return 0;
}
