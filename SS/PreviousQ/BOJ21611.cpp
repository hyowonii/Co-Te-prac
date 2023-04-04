#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define R first
#define C second

int n;  // 격자 변 길이
int m;  // 횟수
int board[51][51];  // 격자
pair<int,int> boardNum[2500]; // 격자번호
vector<pair<int,int>> ds; // {d:방향,s:거리}
pair<int,int> shark;  // 상어 위치
int dr[4] = {0,1,0,-1}; // 구슬 이동
int dc[4] = {-1,0,1,0};
bool stop = false;  // 폭발 멈춤
int result1 = 0;
int result2 = 0;
int result3 = 0;
int result=0; // 1×(폭발한 1번 구슬의 개수) + 2×(폭발한 2번 구슬의 개수) + 3×(폭발한 3번 구슬의 개수)

// 달팽이 순회 함수
void snail(){
  int cnt=1;
  int num=1;
  int curr = shark.R;
  int curc = shark.C;
  while(num <= n*n-1){
    if(cnt % 2 == 1){ // 홀수번
      for(int i=1; i<=cnt; i++){
        curr += (dr[0]);
        curc += (dc[0]);
        boardNum[num++] = {curr,curc};
      }
      for(int i=1; i<=cnt; i++){
        curr += (dr[1]);
        curc += (dc[1]);
        boardNum[num++] = {curr,curc};
      }
    }
    else{ // 짝수번
      for(int i=1; i<=cnt; i++){
        curr += (dr[2]);
        curc += (dc[2]);
        boardNum[num++] = {curr,curc};
      }
      for(int i=1; i<=cnt; i++){
        curr += (dr[3]);
        curc += (dc[3]);
        boardNum[num++] = {curr,curc};
      }
    }
    cnt++;
  }
}

// 입력
void init(){
  cin >> n >> m;
  for(int r=1; r<=n; r++)
    for(int c=1; c<=n; c++)
      cin >> board[r][c];

  for(int k=0; k<m; k++) {
    int d, s;
    cin >> d >> s;
    ds.push_back({d,s});
  }

  shark = {(n+1)/2, (n+1)/2};

  // 격자번호 초기화
  snail();
}

// print
void print(){
  for(int r=1; r<=n; r++){
    for(int c=1; c<=n; c++){
      cout << board[r][c] << " ";
    }
    cout << "\n";
  }
}

// 1. 상어 블리자드
void blizard(){
  pair<int,int> dns = ds.front();
  ds.erase(ds.begin(), ds.begin()+1);
  int d = dns.first;  // 방향
  int s = dns.second; // 거리

  // 방향
  int drr[5] = {0,-1,1,0,0};
  int dcc[5] = {0,0,0,-1,1};

  for(int i=1; i<=s; i++){
    int rmr = shark.R + (drr[d]*i);
    int rmc = shark.C + (dcc[d]*i);
    if(rmr<=0 || rmr>n || rmc<=0 || rmc>n) continue;
    board[rmr][rmc] = 0;
  }
}

// 2.3-2. 구슬 이동
void moveBeads(){
  int zeroCnt=0;
  for(int i=1; i<=n*n-1; i++){
    auto cur = boardNum[i];
    int curr = cur.R;
    int curc = cur.C;
    if(board[curr][curc] == 0){
      zeroCnt++;
    }
    else{
      if(zeroCnt != 0){
        auto nxt = boardNum[i-zeroCnt];
        int nxtr = nxt.R;
        int nxtc = nxt.C;
        board[nxtr][nxtc] = board[curr][curc];
        board[curr][curc] = 0;
      }
    }
  }
}

// 구슬 폭발 시행해서 지우기
void doBomb(vector<pair<int,int>> sameBead, int curBeadNum){
  for(int i=0; i<sameBead.size(); i++){
    board[sameBead[i].R][sameBead[i].C] = 0;
  }
  if(curBeadNum == 1) result1 += sameBead.size();
  else if(curBeadNum == 2) result2 += sameBead.size();
  else result3 += sameBead.size();

  stop = false;
}

// 3-1. 구슬 폭발
void bomb(){
  auto cur = boardNum[1];
  int curNum = board[cur.R][cur.C];
  vector<pair<int,int>> sameBead;
  sameBead.push_back({cur.R, cur.C});
  for(int i=2; i<=n*n-1; i++){
    auto nxt = boardNum[i];
    int nxtNum = board[nxt.R][nxt.C];
    if(nxtNum != curNum){
      if(sameBead.size() >= 4) {
        doBomb(sameBead, curNum);
      }
      curNum = nxtNum;
      sameBead.clear();
    }
    sameBead.push_back({nxt.R, nxt.C});
    if(nxtNum == 0) break;
  }
  if(sameBead.size() >= 4) {
    doBomb(sameBead, curNum);
  }
}

// 4. 구슬 변화
void changeBeads(){
  int newBoard[51][51] ={0};
  int idx = 1;
  int a = 1;  // 구슬 개수
  int b = board[boardNum[1].R][boardNum[1].C];  // 구슬 번호
  for(int i=2; i<=n*n-1; i++){
    if(idx >= n*n) break;
    int nxt = board[boardNum[i].R][boardNum[i].C];
    if(nxt == b){
      a++;
    }
    else{
      auto savea = boardNum[idx++];
      auto saveb = boardNum[idx++];
      newBoard[savea.R][savea.C] = a;
      newBoard[saveb.R][saveb.C] = b;
      a = 1;
      b = nxt;
    }
    if(nxt == 0) break;
  }
  fill(&board[0][0], &board[n+1][n+1], 0);
  copy(&newBoard[0][0], &newBoard[n+1][n+1], &board[0][0]);
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // 입력
  init();
  
  while(m--){

    // 1. 상어 블리자드
    blizard();

    // 2. 구슬 이동
    moveBeads();

    while(true){  // 폭발할 구슬이 없을 때 까지
      
      stop = true;

      // 3-1. 구슬 폭발
      bomb();

      if(stop) break;
      
      // 3-2. 구슬 이동
      moveBeads();
    }
    
    // 4. 구슬 변화
    changeBeads();

  }
  result = 1 * result1 + 2 * result2 + 3 * result3;
  cout << result;
}