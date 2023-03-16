/*
	백준 [연결 요소의 개수]
	https://www.acmicpc.net/problem/11724
	bfs
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;	// 정점 개수
int M;	// 간선 개수
vector<int> b[1001];
bool vis[1001];
int result = 0;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	while(M--){
		int u, v;
		cin >> u >> v;
		b[u].push_back(v);
		b[v].push_back(u);
	}


	for(int i=1; i<=N; i++){
		if(vis[i] == true) continue;
		queue<int> q;
		q.push(i);	vis[i] = true;	// 큐에 넣을 때 확실히 방문
		while(!q.empty()){
			int cur = q.front();	q.pop();	
			for(auto nxt : b[cur]){
				if(vis[nxt] == true) continue;
				q.push(nxt);	vis[nxt] = true;
			}
		}
		result++;
	}

	cout << result;

}