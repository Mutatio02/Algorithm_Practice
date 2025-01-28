#include <bits/stdc++.h>
using namespace std;
// 25.1.28 시뮬레이션(사다리 조작)
int N,M,H;
int board[31][31]; // 0은 미연결 1은 연결
vector<pair<int,int>> dot;
int ans = 4; // 최대 3개의 경우의 수

bool check() {
    for(int i=1; i<=N; i++) { // 세로
        int cur = i;
        for(int j=1; j<=H; j++) { // 가로
            if(board[j][cur]) cur++; // 현재 오른쪽 연결이 있으면 오른쪽으로
            else if(board[j][cur-1]) cur--; // 왼쪽이 연결이 있으면 왼쪽으로
        }
        if(cur!=i) return false; // 만약 현재 번호와 다르면 실패
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;

    for(int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        board[a][b] =1;
    }

    for(int i=1; i<=H; i++) {
        for(int j=1; j<=N; j++) {
            if(board[i][j-1] || board[i][j] || board[i][j+1]) continue;
            dot.push_back({i,j});
        }
    }

    if(check()) { // 현재 번호와 같다면 더이상 추가할 필요가 없다
        cout << 0;
        return 0;
    }
    int opper = dot.size();

    for(int i=0; i<opper; i++) {
        board[dot[i].first][dot[i].second] = 1; // 연결
        if(check()) ans = min(ans,1);
        for(int j=i+1; j<opper; j++) {
            board[dot[j].first][dot[j].second] = 1; // 연결
            if(check()) ans = min(ans,2);
            for(int k=j+1; k<opper; k++) {
                board[dot[k].first][dot[k].second] = 1; // 연결
                if(check()) ans = min(ans,3);
                board[dot[k].first][dot[k].second] = 0; // 복구
            }
            board[dot[j].first][dot[j].second] =0; // 복구
        }
        board[dot[i].first][dot[i].second] = 0; // 복구
    }
    
    if(ans>3) ans = -1;
    cout << ans;
    
    return 0;
}
