/*
	백준 [말이 되고픈 원숭이]
	https://www.acmicpc.net/problem/1600
	bfs
*/

#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int hx[8] = { -2,-1,1,2,2,1,-1,-2 };
int hy[8] = { -1,-2,-2,-1,1,2,2,1 };

int board[202][202];
bool vis[202][202][31] = { false };
int answer = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<pair<int, int>, int>> Q;
	Q.push({ { 0,0 },0 });
	vis[0][0][0] = true;
	while (!Q.empty()) {
		int sz = Q.size();
		while (sz--) {
			auto cur = Q.front(); Q.pop();
			int x = cur.first.first;
			int y = cur.first.second;
			int count = cur.second;

			if (x == c - 1 && y == r - 1) {
				cout << answer;
				return 0;
			}

			if (count < k) {
				for (int i = 0; i < 8; i++) {
					int nx = x + hx[i];
					int ny = y + hy[i];
					int ncount = count + 1;

					if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
					if (vis[nx][ny][ncount]) continue;
					if (board[nx][ny] == 1) continue;
					vis[nx][ny][ncount] = true;
					Q.push({ { nx,ny }, ncount });
				}
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int ncount = count;

				if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
				if (vis[nx][ny][ncount]) continue;
				if (board[nx][ny] == 1) continue;
				vis[nx][ny][ncount] = true;
				Q.push({ { nx,ny }, ncount });
			}
		}
		answer++;
	}

	cout << -1;
	return 0;
}