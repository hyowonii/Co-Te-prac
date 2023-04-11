/*
  백준 [숨바꼭질2]
  https://www.acmicpc.net/problem/12851
  BFS
*/

#include <iostream>
using namespace std;
#include <queue>

int N, K;
int dist[100002];
int cnt[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

  if(N == K) {
    cout << 0 << "\n" << 1;
    return 0;
  }

	fill(dist, dist + 100001, -1);
	dist[N] = 0;
  cnt[N] = 1;
	queue<int> Q;
	Q.push(N);

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] == -1) {
        dist[nxt] = dist[cur] + 1;
        Q.push(nxt);
        cnt[nxt] = cnt[cur];
      }
      else{
        if(dist[nxt] == dist[cur] + 1){
          cnt[nxt] += cnt[cur];
        }
      }
		}
	}
	cout << dist[K] << "\n" << cnt[K];
}