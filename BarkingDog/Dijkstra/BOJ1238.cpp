/*
  백준 [파티]
  https://www.acmicpc.net/problem/1238
  다익스트라
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f

int N;  // N개의 도시, N명의 학생
int M;  // 단방향 도로의 개수
int X;  // 목적지 도시 번호
vector<pair<int, int>> road[1001];  // 출발점 - {소요시간, 끝점}
int d[1001][1001];  // 출발점 - 도착점 최단거리 테이블
int mx = 0;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> X;
  while(M--){
    int v1, v2, w;
    cin >> v1 >> v2 >> w;
    road[v1].push_back({w, v2});
  }

  for(int s=1; s<=N; s++){  // s번 도시에서 출발
    fill(d[s], d[s]+N+1, INF);
    d[s][s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
      auto cur = pq.top();  pq.pop();
      if(d[s][cur.second] != cur.first) continue; 
      for(auto nxt : road[cur.second]){
        if(d[s][nxt.second] <= nxt.first + d[s][cur.second]) continue;
        d[s][nxt.second] = nxt.first + d[s][cur.second];
        pq.push({d[s][nxt.second], nxt.second});
      }
    }
  }

  for(int s=1; s<=N; s++) {
    int sres = d[s][X] + d[X][s];
    if(sres >= mx) mx = sres;
  }

  cout << mx;
}