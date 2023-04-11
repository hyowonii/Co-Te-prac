/* 오답?
  백준 [숨바꼭질4]
  https://www.acmicpc.net/problem/13913
  bfs
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int dist[100002];
vector<int> way[100002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;

  if(n == k){
    cout << 0 << "\n" << 0;
    return 0;
  }

  fill(dist, dist+100001, -1);
  dist[n] = 0;
  way[n].push_back(n);
  queue<int> q;
  q.push(n);

  while(dist[k] == -1){
    int cur = q.front();  q.pop();

    for(int nxt : {cur-1, cur+1, cur*2}){
      if(nxt < 0 || nxt > 100000) continue;
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      way[nxt] = way[cur];
      way[nxt].push_back(nxt);
      q.push(nxt);
    }
  }

  cout << dist[k] << "\n";
  for(int i=0; i<way[k].size(); i++)
    cout << way[k][i] << " ";
}