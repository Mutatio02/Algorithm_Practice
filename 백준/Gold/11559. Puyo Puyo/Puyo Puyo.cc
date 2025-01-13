#include <bits/stdc++.h>
using namespace std;

bool bomb; // 뿌요가 터졌는지 여부
bool vis[12][6]; // 필드 방문 여부
string board[12]; // 필드 상태
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int cnt;

// vis 배열 초기화
void reset(){
  for(int i = 0; i < 12; ++i)
    for(int j = 0; j < 6; ++j)
      vis[i][j] = false;
}

void bfs(int x, int y){
  vis[x][y] = true;
  char color = board[x][y];
  queue<pair<int, int> > que;
  vector<pair<int, int>> vec; // tmp: 4개 이상일 경우 뿌요를 지우기 위해 위치를 저장하는 vector
  que.push({x, y}); vec.push_back({x, y});
  while(!que.empty()){
    pair<int, int> cur = que.front(); que.pop();
    for(int i = 0; i < 4; ++i){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
      if(vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue;
      vis[nx][ny] = true;
      que.push({nx, ny}); vec.push_back({nx, ny});
    }
  }

  if(vec.size() >= 4){
    bomb = true;
    for(auto cur : vec)
      board[cur.first][cur.second] = '.';    
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 12; ++i)
    cin >> board[i];
  do{
    bomb = false; // 뿌요가 터졌는지 여부
    for(int i = 0; i < 6; ++i){
      // 필드의 빈 칸을 모두 뿌요 위로 올림
      for(int j = 10; j >= 0; --j){
        int tmp = j;
        // 빈 칸일 경우 위치 변경
        while(tmp<11&&board[tmp+1][i]=='.'){
          swap(board[tmp][i], board[tmp+1][i]);
          ++tmp;
        }
      }
    }
    for(int i = 0; i < 12; ++i)
      for(int j = 0; j < 6; ++j)
        if(!vis[i][j]&&board[i][j]!='.')
          bfs(i, j);

    if(bomb) ++cnt; 
    reset();
  }while(bomb); 
  cout << cnt;
}