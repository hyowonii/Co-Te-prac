#include <iostream>
using namespace std;
#include <queue>

#define X first
#define Y second
int T;
int farm[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	queue<pair<int, int>> Q;
	while (T--) {
		farm[50][50] = { 0 };
		int M, N, K;
		cin >> M >> N >> K;

		while (K--) {
			int x, y;
			cin >> x >> y;
			farm[y][x] = 1;
		}

		int num = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (farm[i][j] == 0) continue;
				Q.push({ i,j });
				farm[i][j] = 0;

				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
						if (farm[nx][ny] == 0) continue;

						farm[nx][ny] = 0;
						Q.push({ nx, ny });
					}
				}
				num++;
			}
		}
		cout << num << "\n";
	}
}