#include <iostream>
using namespace std;
#include <queue>

#define X first		// pair
#define Y second	// pair
int n, m;
int board[502][502];
int vis[502][502];	// �湮�Ϸ� ǥ��
int dx[4] = { 1,0,-1,0 };	// ��(��->��->��->��)
int dy[4] = { 0,1,0,-1 };	// ��

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

	for (int i = 0; i < n; i++) {		// ������ ã�� ��ȯ
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;

			queue<pair<int, int>> Q;
			vis[i][j] = 1;	// �湮��
			Q.push({ i,j });	// pair ����

			int area = 0;
			// BFS ���
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx <0 || ny<0 || nx >= n || ny >= m) continue;		// ���� Ȯ��
					if (vis[nx][ny] || board[nx][ny] == 0) continue;

					vis[nx][ny] = 1;	// bfs �湮
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