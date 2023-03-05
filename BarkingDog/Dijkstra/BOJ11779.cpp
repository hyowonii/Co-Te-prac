/*
  백준 [최소비용 구하기2]
  https://www.acmicpc.net/problem/11779
  다익스트라
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define X first
#define Y second

int N;  // 도시 개수
int M;  // 버스 개수
vector<pair<int, int>> bus[1005]; // 버스 입력값 저장: 출발 - {비용, 도착}
int table[1005];  // 키: 도착점, 값: 비용
int s, e; // 출발점, 도착점
// result
int pre[1005];  // **

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a, b, c;
    cin >> a >> b >> c;
    bus[a].push_back({c, b});
  }
  cin >> s >> e;
  fill(table, table+N+1, INF);
  table[s] = 0; // 시작점-시작점 거리 = 0

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({table[s], s});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(cur.X == table[cur.Y]){  // 최솟값임
      for(auto nxt : bus[cur.Y]){
        if(nxt.X + table[cur.Y] < table[nxt.Y]){
          table[nxt.Y] = nxt.X + table[cur.Y];   // 최솟값 갱신
          pq.push({table[nxt.Y], nxt.Y});
          pre[nxt.Y] = cur.Y;
        }
      }
    }
  }

  cout << table[e] << "\n";
  
  vector<int> path;
  int cur = e;
  while(cur != s){
    path.push_back(cur);
    cur = pre[cur];
  }
  path.push_back(s);
  reverse(path.begin(), path.end());
  cout << path.size() << "\n";
  for(auto p : path) cout << p << " ";

}