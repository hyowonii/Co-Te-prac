#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int board[100][100] = { 0 };
deque<pair<int, int>> dq;	// �� ��ġ
queue<pair<int, char>> mv;	// �� �̵����� ����
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int dir = 1;	// dx[dir] �̷� ������. ó�� ������ �������̹Ƿ� 1
int time = 0;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N;
	cin >> K;

	while (K--) {
		int a, b;
		cin >> a >> b;
		board[a - 1][b - 1] = 1;	// ���
	}

	int L;
	cin >> L;
	while (L--) {
		int m;
		char d;
		cin >> m >> d;
		mv.push({m, d});
	}

	dq.push_back({0, 0});
	board[0][0] = 2;	// �� ��
	int srow = 0;
	int scol = 0;

	while (srow >= 0 && srow < N && scol >= 0 && scol < N) {
		time++;

		srow = dq.front().first;
		scol = dq.front().second;

		// �Ӹ� �̵�
		srow += dx[dir];
		scol += dy[dir];
		dq.push_front({ srow, scol });

		if (board[srow][scol] == 2) break;
		if (board[srow][scol] == 0) {	// ��� ������
			board[dq.back().first][dq.back().second] = 0;
			dq.pop_back();	// ���� ����
		}

		if (!mv.empty() && (time == mv.front().first)) {
			if (mv.front().second == 'D') dir = (dir + 1) % 4;
			else if (mv.front().second == 'L') dir = (dir + 3) % 4;
			mv.pop();
		}

		board[srow][scol] = 2;

	}

	cout << time;
}