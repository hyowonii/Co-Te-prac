#include <iostream>
using namespace std;
#include <queue>

#define X first		// pair
#define Y second	// pair
int n, m;
int board[502][502];
int vis[502][502];	// 방문완료 표시
int dx[4] = { 1,0,-1,0 };	// 행(남->서->북->동)
int dy[4] = { 0,1,0,-1 };	// 열

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	int mx = 0;
	int num = 0;

	for (int i = 0; i < n; i++) {		// 시작점 찾기 순환
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;

			queue<pair<int, int>> Q;
			vis[i][j] = 1;	// 방문함
			Q.push({ i,j });	// pair 삽입

			int area = 0;
			// BFS 계산
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx <0 || ny<0 || nx >= n || ny >= m) continue;		// 범위 확인
					if (vis[nx][ny] || board[nx][ny] == 0) continue;

					vis[nx][ny] = 1;	// bfs 방문
					Q.push({ nx, ny });
				}
				area++;
			}
			mx = max(area, mx);
			num++;
		}
	}
	cout << num << "\n" << mx;
}