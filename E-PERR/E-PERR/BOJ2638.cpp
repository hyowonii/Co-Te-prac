#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pr;
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,-1,0,1 };

// ġ�� �ܺ� ����: -1, ���� ����: 0���� ǥ��
void dfs(int n, int m, int row, int col, vector<vector<int>>& board) {
	
	if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 0) return;		// ġ�� �ܺ� ���� �ƴϸ� ����
	
	board[row][col] = -1;		// ġ�� �ܺ� �������� ǥ��
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
			if (board[i][j] != 1) continue;		// ġ� �ƴϸ� �о�
			
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];

				if (board[nr][nc] == -1) cnt++;		// �ܺο� ������
			}

			if (cnt >= 2) q.push({i, j});		// �ܺ� ������ 2�� �̻� ������ ���� �� �ִ� ġ��� ����
		}
	}

	return q;
}

int solution(int n, int m, vector<vector<int>> &board) {
	int answer = 0;
	dfs(n, m, 0, 0, board);		// ù ���� �� ġ�� ���ܺ� ���� ���� (���������� dfs ������)

	while (true) {	// ��� ġ�� ���� ������ �ݺ���

		queue<pr> q = meltingChese(n, m, board);		// ���� �� �ִ� ġ�� ã�Ƽ� ����

		if (q.empty()) break;	// ��� ġ� �� ��Ҵٸ� ����
			
		while (!q.empty()) {	// q�� ����ִ� ���� �� �ִ� ġ�� ��� ����
			int row = q.front().first;
			int col = q.front().second;
			board[row][col] = 0;
			dfs(n, m, row, col, board);		// ġ� ���̸鼭 �ܺΰ����� ������� Ȯ�� �� ����
			q.pop();
		}

		answer++;	// ���� �� �ִ� ġ�� �� ���̰� Ƚ��+1
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