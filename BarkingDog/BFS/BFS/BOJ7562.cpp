#include <iostream>
#include <algorithm>
using namespace std;
#include <queue>

int t;
int board[305][305];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int L;
		cin >> L;

		for (int i = 0; i < L; i++)
			for (int j = 0; j < L; j++)
				board[i][j] = -1;
		
		queue<pair<int, int>> Q;

		int a, b;
		cin >> a >> b;
		board[a][b] = 0;
		Q.push({ a,b });

		int finishX, finishY;
		cin >> finishX >> finishY;

		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			if (cur.first == finishX && cur.second == finishY) {
				cout << board[cur.first][cur.second] << "\n";
				break;
			}
			for (int i = 0; i < 8; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
				if (board[nx][ny] != -1) continue;

				board[nx][ny] = board[cur.first][cur.second] + 1;
				Q.push({ nx,ny });
			}
		}
	}
}