#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>

int m, n, h;	// 가로(x), 세로(y), 높이(h)
int board[100][100][100];
int dis[100][100][100];		// 거리 이용
queue<tuple<int, int, int>> Q;
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int result = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)	{	// z
		for (int j = 0; j < n; j++)	{	// y
			for (int k = 0; k < m; k++) {	// x
				int tom;
				cin >> tom;		// 1: 익은, 0: 익지 않은, -1: 없음
				board[k][j][i] = tom;
				if (tom == 1) Q.push({ k,j,i });
				if (tom == 0) dis[k][j][i] = -1;
			}
		}
	}

	while (!Q.empty()) {
		auto tomato = Q.front(); Q.pop();
		int tomX, tomY, tomZ;
		tie(tomX, tomY, tomZ) = tomato;
		
		for (int i = 0; i < 6; i++) {
			int nx = tomX + dx[i];
			int ny = tomY + dy[i];
			int nz = tomZ + dz[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (dis[nx][ny][nz] != -1) continue;
			dis[nx][ny][nz] = dis[tomX][tomY][tomZ] + 1;	// 하루 더하기
			Q.push({ nx, ny, nz });
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < h; k++) {
				if (dis[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				result = max(result, dis[i][j][k]);
			}
		}
	}
	cout << result;
	return 0;
}