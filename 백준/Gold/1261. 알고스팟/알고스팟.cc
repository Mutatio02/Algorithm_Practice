#include <bits/stdc++.h>
using namespace std;

// 25.04.28 알고스팟 (다익스트라)
int N,M;
int wall[105][105];
int dist[105][105];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
const int INF = 1e9;
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            char ch;
            cin >> ch;
            wall[i][j] = ch-'0';
        }
    }    
    for(int i=0; i<N; i++) {
        fill(dist[i],dist[i]+M,INF);
    }

    dist[0][0] = 0; // 시작을 0,0으로 0-based로 변환
    pq.push({0,0,0});
    while(!pq.empty()) {
        int x,y,cost;
        tie(cost,x,y) = pq.top(); // 비용과 정점들
        pq.pop();

        if(dist[x][y]< cost) continue;

        for(int dir = 0; dir<4; dir++) {
            int nx = dx[dir]+x;
            int ny = dy[dir]+y;

            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            
            int nextcost = cost + wall[nx][ny];
            
            if(dist[nx][ny]>nextcost) {
                dist[nx][ny] = nextcost;
                pq.push({dist[nx][ny],nx,ny});
            }
        }
    }
    
    cout << dist[N-1][M-1];
    return 0;
}
