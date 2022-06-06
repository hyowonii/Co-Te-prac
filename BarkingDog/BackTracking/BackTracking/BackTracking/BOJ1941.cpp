#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

string board[5];
bool sev[25];
int result = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) cin >> board[i];

	// 25명 중 후보 7명의 조합 뽑기
	fill(sev + 7, sev + 25, true);

	do {
		int cnt = 0, s_cnt = 0;
		queue<pair<int, int>> Q;

		bool sel7[5][5] = {};
		bool visited[5][5] = {};
		for (int i = 0; i < 25; i++) {
			if (!sev[i]) {
				int x = i / 5, y = i % 5;	// 행, 열
				sel7[x][y] = true;
				if (Q.empty()) {	// 첫번째만 넣음
					Q.push({ x,y });
					visited[x][y] = true;
				}
			}
		}

		while (!Q.empty()) {
			int x, y;
			tie(x, y) = Q.front(); Q.pop();
			cnt++;
			if (board[x][y] == 'S') s_cnt++;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || !sel7[nx][ny] || visited[nx][ny])
					continue;
				Q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}

		if (cnt >= 7 && s_cnt >= 4) result++;


	} while (next_permutation(sev, sev + 25));
	
	cout << result;
}