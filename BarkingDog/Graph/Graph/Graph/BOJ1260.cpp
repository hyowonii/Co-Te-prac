/*
	백준 [DFS와 BFS]
	https://www.acmicpc.net/problem/1260
	dfs, bfs
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int N;	// 정점 개수
int M;	// 간선 개수
int S;	// 시작 정잠
vector<int> b[1005];

bool vvis[1005];	// 재귀dfs

void dfs(){
	bool vis[1005];
	fill(vis, vis + N + 1, false);

	stack<int> s;
	s.push(S);

	vector<int> v;

	while(!s.empty()){
		int cur = s.top();	s.pop();
		if(vis[cur]) continue;
		vis[cur] = true;
		v.push_back(cur);

		for(int i=0; i<b[cur].size(); i++){
			int nxt = b[cur][b[cur].size()-1-i];
			if(vis[nxt]) continue;
			s.push(nxt);
		}
	}

	for(int i=0; i<v.size(); i++) cout << v[i] << " ";
}

// 재귀 dfs
void dfs2(int cur){
	vvis[cur] = true;
	cout << cur << " ";
	for(auto nxt : b[cur]){
		if(vvis[nxt]) continue;
		dfs2(nxt);
	}
}

void bfs(){
	bool vis[1005];
	fill(vis, vis + N + 1, false);

	queue<int> q;
	q.push(S);	vis[S] = true;

	vector<int> v;
	v.push_back(S);

	while(!q.empty()){
		int cur = q.front();	q.pop();

		for(auto nxt : b[cur]){
			if(vis[nxt]) continue;
			v.push_back(nxt);
			q.push(nxt);	vis[nxt] = true;
		}
	}

	for(int i=0; i<v.size(); i++) cout << v[i] << " ";
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> S;
	while(M--){
		int u, v;
		cin >> u >> v;
		b[u].push_back(v);
		b[v].push_back(u);
	}

	for(int i=0; i<=N; i++) sort(b[i].begin(), b[i].end());

	fill(vvis, vvis+N+1, false); //	재귀dfs

	// dfs();
	dfs2(S);
	cout << "\n";
	bfs();

}