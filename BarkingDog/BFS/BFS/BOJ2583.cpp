/*
	백준 [영역 구하기]
	https://www.acmicpc.net/problem/2583
	bfs
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int board[101][101];
bool visited[101][101] = { false };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> answer;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, k;
	cin >> m >> n >> k;
	while (k--) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		for (int i = ly; i < ry; i++) {
			for (int j = lx; j < rx; j++) {
				board[i][j] = 1;
			}
		}
	}

	queue<pair<int, int>> Q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0) continue;
			if (visited[i][j]) continue;
			
			Q.push({ i,j }); 
			visited[i][j] = true;
			int cnt = 1;
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int p = 0; p < 4; p++) {
					int nx = cur.first + dx[p];
					int ny = cur.second + dy[p];

					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != 0) continue;
					if (visited[nx][ny]) continue;
					cnt++;
					visited[nx][ny] = true;
					Q.push({ nx,ny });
				}
			}
			answer.push_back(cnt);
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}