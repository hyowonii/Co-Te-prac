/*
  죽어도 이해 안되는 공중부양1........
  해결 못함

  해결함!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

#include <iostream>
#include <vector>
using namespace std;

int n;  // 어항 수
int k;  // 물고기 수 최대-최소
int cage[104][104]; // 이차원배열
int mx, mn; // 물고기 최대, 최소
int cnt=0;  // 어항정리 횟수(출력값)


// 물고기 수의 최대, 최소 구하기
void findMxMn(){
  int isthismx=0;
  int isthismn=10001;
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<n; j++){
      if(cage[i][j] == 0) continue;
      if(cage[i][j] > isthismx) isthismx = cage[i][j];
      if(cage[i][j] < isthismn) isthismn = cage[i][j];
    }
  }
  mx = isthismx;
  mn = isthismn;
}

// 물고기 수 조절
void bal(){
  int plusminus[104][104] = {0};  // 각 칸의 더하고 뺄 값 총점

  int dx[4] = {0,-1,0,1};
  int dy[4] = {1,0,-1,0};

  for(int i=n-1; i>=0; i--){
    for(int j=n-1; j>=0; j--){
      int cur = cage[i][j];
      if(cur == 0) continue; // 물고기 없으면
      for(int k=0; k<4; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        int nxt = cage[nx][ny];
        if(nx<0 || ny<0 || nx>=n || ny>=n || nxt==0) continue;
        
        int d = abs(cur - nxt) / 5;
        if(d > 0){
          if(nxt > cur){
            plusminus[i][j] += d;
          }
          else{
            plusminus[i][j] -= d;
          }
        } 
      }
    }
  }

  for(int i=n-1; i>=0; i--){
    for(int j=n-1; j>=0; j--){
      if(cage[i][j] == 0) continue;
      cage[i][j] += plusminus[i][j];
    }
  }
}

// 일렬로 놓기
void layDown(){
  vector<int> newArr;
  for(int j=0; j<n; j++){
    if(cage[n-1][j] == 0) continue;
    int i = n-1;
    while(cage[i][j] != 0 && i >= 0){
      newArr.push_back(cage[i][j]);
      i--;
    }
  }

  fill(&cage[0][0], &cage[n][n], 0);
  // memset(cage, 0, sizeof(cage));
  for(int j=0; j<n; j++) cage[n-1][j] = newArr[j];
}

// 공중부양1****
void move1(){
  int pivot=1, w=1, h=1;  // 한 단계 앞선 피봇
  for(int idx=0; ; idx++){
    if(pivot + h > n) break;
    // pivot 위치에 w*h 쌓아올리기
    for(int a = n-1; a > n-1 - h; a--){
      for(int b = pivot - w; b < pivot; b++){
        cage[n-1-pivot+b][pivot-a+n-1] = cage[a][b];
        cage[a][b] = 0;
      }
    }
    pivot += h;
    if(idx % 2 == 0) h++;
    else w++;
  }
}

// 공중부양2
void move2(){
  int num = 0;
  int j = n-1;
  int oneLine = n / 4;  // 한줄에 몇개씩
  for(int i=n-2; i>=n-4; i--){
    if(j == n-1){
      for(int k=0; k<oneLine; k++){
        cage[i][j] = cage[n-1][num++];
        j--;
      }
      j += 1;
    }
    else{
      for(int k=0; k<oneLine; k++){
        cage[i][j] = cage[n-1][num++];
        j++;
      }
      j -= 1;
    }
  }

  for(int j=0; j<(n/4)*3; j++) cage[n-1][j] = 0;
}

void print(string title){
  cout << "////////////after " << title << "/////////////\n";
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << cage[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i=0; i<n; i++) cin >> cage[n-1][i]; // 이차원 배열 맨 마지막 행에 넣기

  findMxMn();

  // move1();
  // print("move1");

  while(mx - mn > k){

    // 1. 가장 작은 칸에 +1씩
    for(int j=0; j<n; j++){
      if(cage[n-1][j] == mn) cage[n-1][j] += 1;
    }
    // print("1씩 더하기");

    // 2. 어항 쌓기1(공중부양)****
    move1();
    // print("move1");

    // 3. 물고기 수 조절
    bal();
    // print("수 정렬1");

    // 4. 일렬로 놓기
    layDown();
    // print("일렬로1");

    // 5. 공중부양2
    move2();
    // print("move2");

    // 6. 물고기 수 조절
    bal();
    // print("수정렬2");

    // 7. 일렬로 놓기
    layDown();
    // print("일렬로2");

    findMxMn();
    cnt++;
  }

  cout << cnt;
}