/*
  백준 [플로이드2]
  https://www.acmicpc.net/problem/11780
  플로이드 + 경로 복원
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int N;  // 도시 개수
int M;  // 버스 개수
vector<pair<int, int>> bus[102];  // 출발점 - {거리, 도착점}
int d[102][102];  // 최단거리 테이블
int nxt[102][102];  // 경로 테이블

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<=N; i++) fill(d[i], d[i]+N+1, INF);
  while(M--){
    int v1, v2, w;
    cin >> v1 >> v2 >> w;
    d[v1][v2] = min(d[v1][v2], w);
    nxt[v1][v2] = v2;
    nxt[v2][v1] = v1;
  }
  for(int i=1; i<=N; i++) d[i][i] = 0;

  for(int t=1; t<=N; t++){
    for(int s=1; s<=N; s++){
      for(int e=1; e<=N; e++){
        if(d[s][e] <= d[s][t] + d[t][e]) continue;
        else {
          d[s][e] = d[s][t] + d[t][e];
          nxt[s][e] = nxt[s][t];
        }
      }
    }
  }

  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(d[i][j] == INF) cout << 0 << " ";
      else cout << d[i][j] << " ";
    }
    cout << "\n";
  }

  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(d[i][j] == 0 || d[i][j] == INF){
        cout << "0\n";
        continue;
      }
      /*  개수 출력 불가능
      cout << i << " ";
      int k = nxt[i][j];
      while(k != j){
        cout << k << " ";
        k = nxt[k][j];
      }
      cout << k << "\n";
      */

     vector<int> path;  // 경로 저장 벡터
     int k = i;
     while(k != j){
      path.push_back(k);
      k = nxt[k][j];
     }
     path.push_back(k);

     cout << path.size() << " ";
     for(auto p : path) cout << p << " ";
     cout << "\n";
    }
  }
}