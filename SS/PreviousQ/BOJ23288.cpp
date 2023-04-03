#include <iostream>
#include <queue>
using namespace std;
#define R first
#define C second

int n, m; // 지도의 세로, 가로
int k;  // 이동 횟수
int board[22][22] = {0};  // 지도
pair<int,int> dice;  // 주사위
int dr[4] = {0,1,0,-1}; // 주사위 이동 방향(동, 남, 서, 북)
int dc[4] = {1,0,-1,0};
int dir = 0;  // 주사위 이동 방향 인덱스(동:0, 남:1, 서:2, 북:3) 0~3
int diceMap[4][3] = {0}; // 주사위 면
int result = 0; // 총 점수의 합

// 입력 받기
void init(){
  cin >> n >> m >> k;
  for(int r=1; r<=n; r++){
    for(int c=1; c<=m; c++){
      cin >> board[r][c];
    }
  }
  dice = {1,1};

  diceMap[3][1] = 6;
  diceMap[2][1] = 5;
  diceMap[1][1] = 1;
  diceMap[0][1] = 2;
  diceMap[1][0] = 4;
  diceMap[1][2] = 3;
}

// 주사위 돌아간 면 계산
void rollDice(){
  // 내코드
  if(dir == 0){ // 동쪽으로 회전
    int tmp0 = diceMap[3][1];
    int tmp1 = diceMap[1][0];
    int tmp2 = diceMap[1][1];
    int tmp3 = diceMap[1][2];
    diceMap[3][1] = tmp3;
    diceMap[1][0] = tmp0;
    diceMap[1][1] = tmp1;
    diceMap[1][2] = tmp2;
  }
  else if(dir == 1){  // 남
    int tmp0 = diceMap[0][1];
    int tmp1 = diceMap[1][1];
    int tmp2 = diceMap[2][1];
    int tmp3 = diceMap[3][1];
    diceMap[1][1] = tmp0;
    diceMap[2][1] = tmp1;
    diceMap[3][1] = tmp2;
    diceMap[0][1] = tmp3;
  }
  else if(dir == 2){  // 서
    int tmp0 = diceMap[3][1];
    int tmp1 = diceMap[1][0];
    int tmp2 = diceMap[1][1];
    int tmp3 = diceMap[1][2];
    diceMap[3][1] = tmp1;
    diceMap[1][0] = tmp2;
    diceMap[1][1] = tmp3;
    diceMap[1][2] = tmp0;
  }
  else{ // 북
    int tmp0 = diceMap[0][1];
    int tmp1 = diceMap[1][1];
    int tmp2 = diceMap[2][1];
    int tmp3 = diceMap[3][1];
    diceMap[3][1] = tmp0;
    diceMap[0][1] = tmp1;
    diceMap[1][1] = tmp2;
    diceMap[2][1] = tmp3;
  }

  // 개선 코드
  int up, down, left, right, fron, back;
  // 6개의 수를 모두 저장한 다음 케이스별로 업뎃
  // dice를 일차원배열로 둬도 됨
}

// 1. 주사위 이동 방향으로 한 칸 이동 + **주사위 돌아간 면 계산**
void moveDice(){
  int nxtr = dice.R + dr[dir];
  int nxtc = dice.C + dc[dir];
  if(nxtr<=0 || nxtr>n || nxtc<=0 || nxtc>m) {
    dir = (dir + 2) % 4;
    nxtr = dice.R + dr[dir];
    nxtc = dice.C + dc[dir];
  }
  rollDice();
  dice = {nxtr, nxtc};

  // cout << "dice: (" << dice.R << ", " << dice.C << ")\n";
}

// 2. 주사위 도착한 칸에서 점수 획득
void gainScore(){
  int b = board[dice.R][dice.C];
  int c=1;  // 이동 가능 칸 개수

  int mr[4] = {0,1,0,-1}; 
  int mc[4] = {1,0,-1,0};
  queue<pair<int, int>> Q;
  Q.push(dice);
  bool vis[22][22] = {0};
  vis[dice.R][dice.C] = true;
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int i=0; i<4; i++){
      int nxtr = cur.R + mr[i];
      int nxtc = cur.C + mc[i];
      if(nxtr<=0 || nxtr>n || nxtc<=0 || nxtc>m) continue;
      if(vis[nxtr][nxtc]) continue;
      if(board[nxtr][nxtc] != b) continue;
      c++;
      vis[nxtr][nxtc] = true;
      Q.push({nxtr, nxtc});
    }
  }
  // cout << "b: " << b << ", c: " << c << "\n";
  result += (b * c);
}

// 3. 주사위 이동방향 결정
void decideDir(){
  int a = diceMap[3][1];  // 주사위 아랫면
  int b = board[dice.R][dice.C];  // 칸에 적힌 정수

  if(a > b) dir = (dir + 1) % 4;  // 시계방향
  else if(a < b) dir = (dir - 1 + 4) % 4; // 반시계방향
  // else dir = dir;

  // cout << "newDir: " << dir << "\n";
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // 입력 받기
  init();

  while(k--){
    // 1. 주사위 이동 방향으로 한 칸 이동 + 주사위 돌아간 면 계산
    moveDice();

    // 2. 주사위 도착한 칸에서 점수 획득
    gainScore();

    // 3. 주사위 이동방향 결정
    decideDir();
  }


  cout << result;

}