#include <iostream>
#include <algorithm>
using namespace std;
#define N first
#define M second

int n;  // 보드 세로
int m;  // 보드 가로
char board[10][10];  // 보드
bool vis[11][11][11][11]; // *****

int dn[4] = {0,1,0,-1};
int dm[4] = {1,0,-1,0};
int result=11;


void move(int &curn, int &curm, int ndir, int mdir, int &d){
  while(board[curn+ndir][curm+mdir] != '#'){  // **** cur + dir
    curn += ndir;
    curm += mdir;
    d++;
    if(board[curn][curm] == 'O') break;
  }
}

void recurse(int rn, int rm, int bn, int bm, int cnt){
  if(result <= cnt) return;
  if(cnt > 10) return;

  if((board[rn][rm] == 'O' && board[bn][bm] == 'O') || board[bn][bm] == 'O')
    return;

  if(board[rn][rm] == 'O' && board[bn][bm] != 'O'){ // 빨간공 통과
    result = min(result, cnt);
    return;
  }

  for(int i=0; i<4; i++){
    int ndir = dn[i];
    int mdir = dm[i];

    int nrn=rn, nrm=rm;
    int nbn=bn, nbm=bm;
    int rd=0, bd=0; // **** 두 공이 한 칸에 같이 있는 상황 처리 위해
    move(nrn, nrm, ndir, mdir, rd); // 빨간공 이동
    move(nbn, nbm, ndir, mdir, bd); // 파란공 이동

    // **** 두 공이 겹친 경우
    if(board[nrn][nrm] != 'O' && board[nbn][nbm] != 'O' && nrn==nbn && nrm==nbm){
      if(rd < bd){
        nbn -= ndir;
        nbm -= mdir;
      }
      else {
        nrn -= ndir;
        nrm -= mdir;
      }
    }

    // ****
    if(!vis[nrn][nrm][nbn][nbm]){
      vis[nrn][nrm][nbn][nbm] = true; // ****
      recurse(nrn, nrm, nbn, nbm, cnt+1); 
      vis[nrn][nrm][nbn][nbm] = false;  // ****
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int rn, rm, bn, bm;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      char c;
      cin >> c;
      if(c == 'R'){
        board[i][j] = '.';
        rn = i; rm = j;
      }
      else if(c == 'B'){
        board[i][j] = '.';
        bn = i; bm = j;
      }
      else board[i][j] = c;
    }
  }

  vis[rn][rm][bn][bm] = true;
  recurse(rn, rm, bn, bm, 0);

  if(result > 10) cout << -1;
  else cout << result;
}