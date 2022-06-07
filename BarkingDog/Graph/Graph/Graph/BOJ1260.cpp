/*
	���� [DFS�� BFS]
	https://www.acmicpc.net/problem/1260
	dfs, bfs
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int N, M, V;
vector<int> adj[1005];
bool vis[1005];

// ����� dfs
void dfs_nonRecurse() {
	stack<int> s;
	s.push(V);
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		if (vis[cur]) continue;
		vis[cur] = true;
		cout << cur << " ";

		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][adj[cur].size() - 1 - i];	// ���� -> ������ �������� �־�� ��
			if (vis[nxt]) continue;
			s.push(nxt);
		}
	}
}

// ��� dfs
void dfs(int cur) {

	if (vis[cur]) return;

	vis[cur] = true;	// �湮
	cout << cur << " ";
	for (auto nxt : adj[cur]) {
		if (vis[nxt]) continue;
		dfs(nxt);
		//		vis[nxt] = true;	// ��� ��
	}
}

void bfs() {
	queue<int> Q;
	Q.push(V);	// ���� ����
	cout << V << " ";	// ���
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		vis[cur] = true;	// �湮
		for (auto nxt : adj[cur]) {	// ���� Ȯ���ϴ� ������ ����� �ٸ� ������
			if (vis[nxt]) continue;
			cout << nxt << " ";
			Q.push(nxt);
			vis[nxt] = true;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> V;
	while (M--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v); sort(adj[u].begin(), adj[u].end());
		adj[v].push_back(u); sort(adj[v].begin(), adj[v].end());
	}

	// DFS
//	dfs_nonRecurse();
	dfs(V);

	fill_n(vis, 1005, 0);
	cout << "\n";

	// BFS
	bfs();
}