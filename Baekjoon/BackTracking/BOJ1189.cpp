/*
  백준 [컴백홈]
  https://www.acmicpc.net/problem/1189
  백트래킹
*/

#include <iostream>
using namespace std;

int r, c, k;
char board[5][5];
int si, sj, ei, ej;
int result = 0;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1};

void dfs(int i, int j, int num, bool vis[5][5]){
  if(num == k && i == ei && j == ej){
    result++;
    return;
  }
  if(num >= k) return;
  if(i == ei && j == ej) return;

  for(int k=0; k<4; k++){
    int ni = i + dr[k];
    int nj = j + dc[k];
    if(board[ni][nj] == 'T') continue;
    if(ni<0 || ni>=r || nj<0 || nj>=c) continue;
    if(vis[ni][nj]) continue;
    vis[ni][nj] = true;
    dfs(ni, nj, num+1, vis);
    vis[ni][nj] = false;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> r >> c >> k;
  for(int i=0; i<r; i++){
    string str;
    cin >> str;
    for(int j=0; j<c; j++){
      board[i][j] = str[j];
    }
  }

  si = r-1; sj = 0;
  ei = 0; ej = c-1;

  bool vis[5][5] = {false};
  vis[si][sj] = true;
  dfs(si, sj, 1, vis);

  cout << result;
}