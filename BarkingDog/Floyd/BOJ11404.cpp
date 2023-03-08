/*
  백준 [플로이드]
  https://www.acmicpc.net/problem/11404
  플로이드
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

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<=N; i++) fill(d[i], d[i]+N+1, INF);
  while(M--){
    int v1, v2, w;
    cin >> v1 >> v2 >> w;
    d[v1][v2] = min(d[v1][v2], w);
  }
  for(int i=1; i<=N; i++) d[i][i] = 0;

  for(int t=1; t<=N; t++){
    for(int s=1; s<=N; s++){
      for(int e=1; e<=N; e++){
        d[s][e] = min(d[s][e], d[s][t] + d[t][e]);
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
}