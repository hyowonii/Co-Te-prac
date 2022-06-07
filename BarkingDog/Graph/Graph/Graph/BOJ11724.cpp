/*
	백준 [연결 요소의 개수]
	https://www.acmicpc.net/problem/11724
	bfs
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> adj[1005];
bool vis[1005];
int result = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// BFS
	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		queue<int> Q;
		Q.push(i);
		vis[i] = true;	// 방문
		while (!Q.empty()) {	// 연결된 정점 다 확인
			int cur = Q.front(); Q.pop();
			for (auto nxt : adj[cur]) {
				if (vis[nxt]) continue;
				Q.push(nxt);
				vis[nxt] = true;
			}
		}
		result++;
	}

	cout << result;
}