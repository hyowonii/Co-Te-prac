#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pr;
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,-1,0,1 };

// 치즈 외부 공간: -1, 내부 공간: 0으로 표시
void dfs(int n, int m, int row, int col, vector<vector<int>>& board) {
	
	if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 0) return;		// 치즈 외부 공간 아니면 리턴
	
	board[row][col] = -1;		// 치즈 외부 공간으로 표시
	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];
		dfs(n, m, nr, nc, board);
	}
}

queue<pr> meltingChese(int n, int m, vector<vector<int>>& board) {
	queue<pr> q;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 1) continue;		// 치즈가 아니면 패쓰
			
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];

				if (board[nr][nc] == -1) cnt++;		// 외부와 만나면
			}

			if (cnt >= 2) q.push({i, j});		// 외부 공간과 2번 이상 만나면 녹을 수 있는 치즈로 저장
		}
	}

	return q;
}

int solution(int n, int m, vector<vector<int>> &board) {
	int answer = 0;
	dfs(n, m, 0, 0, board);		// 첫 시작 후 치즈 내외부 공간 구분 (시작점에서 dfs 돌려서)

	while (true) {	// 모든 치즈 녹을 때까지 반복문

		queue<pr> q = meltingChese(n, m, board);		// 녹을 수 있는 치즈 찾아서 저장

		if (q.empty()) break;	// 모든 치즈가 다 녹았다면 종료
			
		while (!q.empty()) {	// q에 들어있는 녹을 수 있는 치즈 모두 녹임
			int row = q.front().first;
			int col = q.front().second;
			board[row][col] = 0;
			dfs(n, m, row, col, board);		// 치즈를 녹이면서 외부공간이 생겼는지 확인 후 변경
			q.pop();
		}

		answer++;	// 녹을 수 있는 치즈 다 녹이고 횟수+1
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, answer;

	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	answer = solution(n, m, board);
	cout << answer;
}