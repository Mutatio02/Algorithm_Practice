#include <bits/stdc++.h>
using namespace std;
// 25.01.11 시뮬레이션(치킨배달 복습)
int N,M;
int board[51][51];
int dist = 0;
vector<pair<int,int>> chick;
vector<pair<int,int>> home;
int ans = INT_MAX;

int calcul(const vector<int>& select) {
    int total_dist = 0;
    for(auto h: home) {
        int hx = h.first;
        int hy = h.second;
        int dist = INT_MAX;

        for(int idx : select ) {
            int cx = chick[idx].first;
            int cy = chick[idx].second;

            dist = min(dist,abs(cx-hx) + abs(cy-hy));
        }
        total_dist += dist;
    }
    return total_dist;
}

void back_track(int k,vector<int>& select) {
    if(select.size() == M) {
        ans = min(ans,calcul(select));
        return;
    }
    
    for(int i=k; i<chick.size(); i++) {
        select.push_back(i);
        back_track(i+1,select);
        select.pop_back();
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];

            if(board[i][j] == 1) {
                home.push_back({i,j}); // 집 좌표
            }
            else if(board[i][j] == 2) {
                chick.push_back({i,j}); // 치킨집 좌표
            }
        }
    }
    vector<int> select; // 선택할 치킨집

    back_track(0,select);

    cout << ans;

    return 0;
}