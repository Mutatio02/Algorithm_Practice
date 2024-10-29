#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int board[501][501];
int T = 987654321;
int height = 0;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,M,B;
    cin >> N >> M >> B; // 세로 가로 블록 수

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
        }    
    }

    for(int h= 0; h<=256; h++) {
        int add = 0;
        int remove = 0;
        for(int i = 0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(board[i][j] > h) {
                    remove += board[i][j] - h;
                }
                else if(board[i][j] == h) {
                    continue;
                }
                else if(board[i][j] < h) {
                    add += h - board[i][j];
                }
            }
        }
        if(remove + B >= add) {
            int tmp = remove * 2 + add;
            if(T >= tmp) {
                T = tmp;
                height = h;
            }
        }
    }

    cout << T << ' ' << height;
    return 0;
}
