#include <iostream>
using namespace std;
#include <queue>

#define X first	
#define Y second
int R, C;
string maze[1002];
int vis[1002][1002];
int jh[1002][1002];		// ÁöÈÆ
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;
	for (int i = 0; i < R; i++) {
		cin >> maze[i];
		for (int j = 0; j < C; j++) {
			if (maze[i][j] == '#') continue;
			if (maze[i][j] == 'F') {
				Q1.push({ i,j });
				continue;
			}
			if (maze[i][j] == 'J') {
				Q2.push({ i,j });
				continue;
			}
			vis[i][j] = -1;
			jh[i][j] = -1;
		}
	}

	while (!Q1.empty()) {
		auto cur = Q1.front();
		Q1.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (vis[nx][ny] >= 0) continue;

			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			Q1.push({ nx, ny });
		}
	}

	while (!Q2.empty()) {
		auto cur = Q2.front();
		Q2.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C) {		// ¹üÀ§¸¦ ¹þ¾î³² == Å»Ãâ ¼º°ø
				cout << jh[cur.X][cur.Y] + 1;
				return 0;
			}
			if (jh[nx][ny] >= 0) continue;
			if (vis[nx][ny] != -1 && vis[nx][ny] <= jh[cur.X][cur.Y] + 1) continue;
			jh[nx][ny] = jh[cur.X][cur.Y] + 1;
			Q2.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";

}