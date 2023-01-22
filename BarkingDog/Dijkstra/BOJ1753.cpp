/*
  BOJ1753 [최단경로]
  https://www.acmicpc.net/problem/1753
  다익스트라
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second
#define INF 1e9+10

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int V, E;
  cin >> V >> E;

  int st;
  cin >> st;

  vector<pair<int, int>> adj[30005]; // 출발 간선 - {거리(비용), 간선 번호}
  for(int i=0; i<E; i++) {
    int v1, v2, w;
    cin >> v1 >> v2 >> w;
    adj[v1].push_back({w, v2});
  }

  int d[20005]; // 최단 거리 테이블
  fill(d, d+V+1, INF);
  d[st] = 0;

  // 우선순위 큐
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  pq.push({d[st], st}); // 시작점 추가
  while(!pq.empty()) {
    auto cur = pq.top();  pq.pop(); // 우선순위 큐에서 가장 거리가 작은 원소를 선택 => 우선순위 큐를 사용하는 & (거리, 정점) 쌍으로 삽입하는 이유
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]) {  // 선택한 정점에서 갈 수 있는 정점들을 모두 살펴봄
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;  // 이미 더 작은 거리값이 기록되어 있을 경우 패쓰
      d[nxt.Y] = d[cur.Y] + nxt.X;  // 최단거리 갱신
      pq.push({d[nxt.Y], nxt.Y}); // (거리, 정점) 쌍 삽입
    }
  }

  for(int i=1; i<=V; i++) {
    if(d[i] == INF) cout << "INF\n";
    else cout << d[i] << "\n";
  }

}