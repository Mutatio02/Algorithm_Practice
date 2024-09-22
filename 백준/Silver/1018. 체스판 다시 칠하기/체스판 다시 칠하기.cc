#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
char arr[51][51];
char WB[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};

char BW[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};
int white_count (int x,int y) {
    int count = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(arr[i+x][j+y]!=WB[i][j]) {
                count++;
            }
        }
    }
    return count;
}
int black_count (int x,int y) {
    int count = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(arr[i+x][j+y]!=BW[i][j]) {
                count++;
            }
        }
    }
    return count;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    int white;
    int black;
    int answer = 64; // 최대 (8*8)
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<=N-8; i++) {
        for(int j=0; j<=M-8; j++) {
            white = white_count(i,j);
            black = black_count(i,j);
            answer = min(answer,min(white,black));
        }
    }

    cout << answer;
    return 0;
}
