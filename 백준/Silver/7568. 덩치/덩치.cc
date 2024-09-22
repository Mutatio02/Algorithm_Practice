#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int,int>> v(N);
    
    int score = 1;
    for(int i=0; i<N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(v[i].first < v[j].first && v[i].second < v[j].second) {
                score++;
            }
        }
        cout << score << " ";
        score = 1;
    }


    return 0;
}
