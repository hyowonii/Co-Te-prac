/*
  해결X
  - 상어 움직임 구현
  - 물고기 저장하는 형태 vector<Fish> Fmap[][] 이런식으로 하면 좋았을듯 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m;  // 물고기 수
int s;  // 연습 횟수
int board[5][5];  // 보드판, 물고기 냄새 기록(0이면 없고 1,2)

// 상어 이동 중
// int rmFishCnt=0;  // 물고기 제거 수
// int moveDic = 000;  // 사전번호
//

int result=0; // 최종 물고기 개수

pair<int, int> shark; // 상어 위치(r, c)

struct Fish
{
  int r;  
  int c;  
  int d;  // 방향 
};
vector<Fish> F; // 원래 물고기
vector<Fish> nF;  // 새로 물고기


// 물고기가 움직이는 방향 계산
pair<int,int> calMove(int d){
  int dr, dc;
  switch(d){
    case 1:
      dr = 0;
      dc = -1;
    case 2:
      dr = -1;
      dc = -1;
    case 3:
      dr = -1;
      dc = 0;
    case 4:
      dr = -1;
      dc = +1;
    case 5:
      dr = 0;
      dc = +1;
    case 6:
      dr = +1;
      dc = +1;
    case 7:
      dr = +1;
      dc = 0;
    case 8:
      dr = +1;
      dc = -1;
  }

  return {dr, dc};
}

// 물고기 한칸씩 움직이기
void moveFish(){
  for(auto f : F){
    // 물고기 이동 계산
    for(int i=0; i<8; i++){
      int nd = (f.d - i + 8) % 8;
      if(nd==0) nd=8;

      pair<int,int> p = calMove(nd);  // (dr, dc)
      int nxtr = f.r + p.first;
      int nxtc = f.c + p.second;
      if(nxtr<1 || nxtc<1 || nxtr>=5 || nxtc>=5) continue;  // 격자 넘어가면
      if(board[nxtr][nxtc]) continue; // 물고기 냄새 있는 칸
      if(nxtr == shark.first && nxtc == shark.second) continue; // 상어 있는 칸

      nF.push_back({nxtr, nxtc, f.d});  // 이동 
    } 
  }
}

/* 내가 짠 코드 메모리초과
// 한 번 이동, {제거 물고기 개수, 사전번호} 리턴
void moveSharkOne(vector<Fish> tmp, pair<int,int> tmpSh, int rmCnt, string dic, int cnt){
  if(cnt == 3) {
    if(rmCnt > rmFishCnt){
      rmFishCnt = rmCnt;
      moveDic = max(moveDic, stoi(dic));
    }
    return;
  }

  int dr[4] = {-1,0,1,0}; // 상1, 좌2, 하3, 우4
  int dc[4] = {0,-1,0,1};
  int vis[5][5] = {0};
  for(int i=0; i<4; i++){
    int nxtr = tmpSh.first + dr[i];
    int nxtc = tmpSh.second + dc[i];
    if(nxtr<1 || nxtc<1 || nxtr>=5 || nxtc>=5) continue;
    if(vis[nxtr][nxtc]) continue;
    for(int k=0; k<tmp.size(); k++){  // 시간복잡도
      Fish f = tmp[k];
      if(f.r == nxtr && f.c == nxtc){ // 물고기 있는 칸
        tmp.erase(tmp.begin() + k);
        rmCnt++;
        break;
      }
    }
    tmpSh.first = nxtr;
    tmpSh.second = nxtc;
    dic += to_string(i+1);
    vis[nxtr][nxtc] = 1;
    moveSharkOne(tmp, tmpSh, rmCnt, dic, cnt);
  }
}

// 상어 이동
void moveShark(){
  moveSharkOne(nF,shark,0,"",0);

  // 상어 진짜 이동
  for(int i=100; i>=1; i /= 10){
    int dr[4] = {-1,0,1,0}; // 상1, 좌2, 하3, 우4
    int dc[4] = {0,-1,0,1};
    int qqq = moveDic / i;
    int nxtr = shark.first + dr[qqq - 1];
    int nxtc = shark.second + dc[qqq - 1];
    for(int k=0; k<nF.size(); k++){  // 시간복잡도
      Fish f = nF[k];
      if(f.r == nxtr && f.c == nxtc){ // 물고기 있는 칸으로 상어 이동
        nF.erase(nF.begin() + k); // 물고기 격자에서 제외
        board[f.r][f.c] = 2;  // 냄새 남김
        break;
      }
    }
    shark.first = nxtr;
    shark.second = nxtc;
    moveDic %= i;
  }
}
*/


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> s;
  for(int i=0; i<m; i++){
    Fish f;
    cin >> f.r >> f.c >> f.d;
    F.push_back(f);
  }
  cin >> shark.first >> shark.second;


  // moveFish();
  // moveShark();


  while(s--){
    // 1. 물고기 1칸 이동
    moveFish();

    // 2. 상어 연속 3칸 이동
    // moveShark();

    // 3. 두 번 전 생긴 물고기 냄새 사라짐
    for(int i=1; i<5; i++){
      for(int j=1; j<5; j++){
        if(board[i][j] == 0) continue; 
        board[i][j]--;
      }
    }

    // 4. 복제 마법(처음 애들이 겹쳐짐)
    for(auto f : nF){
      F.push_back(f);
      nF.clear();
    }

  }

  // 5. 격자에 있는 물고기 세기
  result = F.size();
  
  cout << result;

}