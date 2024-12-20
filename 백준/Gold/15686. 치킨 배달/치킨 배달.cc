#include <bits/stdc++.h>
using namespace std;
int N,M;
int city[51][51];
vector<pair<int,int>> home; // 집의 좌표
vector<pair<int,int>> chick; // 치킨집의 좌표

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> city[i][j];
            if(city[i][j] == 1) {
                home.push_back({i,j});
            }            
            if(city[i][j] == 2) {
                chick.push_back({i,j});
            }
        }
    }

    vector<int> select (chick.size(),1); // 치킨집중 M개를 선택할 조합배열
    fill(select.begin(),select.begin() + chick.size() - M, 0);

    int result = INT_MAX;
    do{
        int chick_dist = 0;
        for(auto h: home) {
            int dist = INT_MAX;
            for(int i=0; i<chick.size(); i++) {
                if(select[i] ==0) continue; // 선택되지 않는 경우는 무시
                dist = min(dist, abs(chick[i].first - h.first) + 
                    abs(chick[i].second - h.second));
            }
            chick_dist += dist;
        }
        result = min(result,chick_dist);
    }while(next_permutation(select.begin(),select.end()));

    cout << result;
    
    return 0;
}
