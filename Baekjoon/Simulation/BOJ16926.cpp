/*
  백준 [배열 돌리기1]
  https://www.acmicpc.net/problem/16926
  구현
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>
using namespace std;

int n, m;
int r;
int A[301][301];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> r;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> A[i][j];
    }
  }

  
  while(r--){
    int B[301][301];
    int si=0, sj=0;
    while(1){
      int ei = (n-1)-si;
      int ej = (m-1)-sj;

      if(si > ei || sj > ej) break; // 종료조건

      int x=si; 
      int y=sj;
      while(x < ei){
        B[x+1][y] = A[x][y];
        x++;
      }
      while(y < ej){
        B[x][y+1] = A[x][y];
        y++;
      }
      while(x > si){
        B[x-1][y] = A[x][y];
        x--;
      }
      while(y > sj){
        B[x][y-1] = A[x][y];
        y--;
      }

      si++; sj++;
    }
    memcpy(&A, &B, sizeof(B));
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }
  
}