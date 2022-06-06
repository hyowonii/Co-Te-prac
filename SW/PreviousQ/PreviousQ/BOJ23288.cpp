/*
�Ｚ �ڵ��׽�Ʈ ���⹮��
�ֻ��� ������ 2
*/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
typedef pair<int, int> pi;

int N, M, K;
int board[21][21];
vector<pi> dir;	// ����
int dirNum = 0;
pi cur;	// �ֻ��� ��ġ
int dice[6] = { 6,4,1,3,5,2 };	// ground, left, sky, right, down, up
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int result = 0;	// ���� ����

void move_dice(int num) {
	int ground = dice[0];
	int left = dice[1];
	int sky = dice[2];
	int right = dice[3];
	int down = dice[4];
	int up = dice[5];

	if (num == 0) {	// ����: (0, +1)
		dice[0] = right;
		dice[3] = sky;
		dice[2] = left;
		dice[1] = ground;
	}
	else if (num == 1) {	// ����: (+1, 0)
		dice[0] = down;
		dice[4] = sky;
		dice[2] = up;
		dice[5] = ground;
	}
	else if (num == 2) {	// ����: (0, -1)
		dice[0] = left;
		dice[1] = sky;
		dice[2] = right;
		dice[3] = ground;
	}
	else {	// ����: (-1, 0)
		dice[0] = up;
		dice[5] = sky;
		dice[2] = down;
		dice[4] = ground;
	}
}

void move(int a, int b) {
	if (a + dir[dirNum].first < 0 || a + dir[dirNum].first >= N || b + dir[dirNum].second < 0 || b + dir[dirNum].second >= M) 
		dirNum = (dirNum + 2) % 4;
	
	cur.first += dir[dirNum].first;
	cur.second += dir[dirNum].second;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> board[i][j];
	// �Է�	

	dir.push_back({ 0,1 });
	dir.push_back({ 1,0 });
	dir.push_back({ 0,-1 });
	dir.push_back({ -1,0 });

	cur.first = 0; cur.second = 0;
	
	while (K--) {
		// �̵�
		move(cur.first, cur.second);
		
		move_dice(dirNum);
		int sdice = dice[0];	// �ֻ����� ground
		int sboard = board[cur.first][cur.second];
		
		// ����
		result += sboard;
		queue<pi> Q;
		Q.push({ cur.first, cur.second });
		int visited[21][21] = { 0 };
		visited[cur.first][cur.second] = 1;
		while (!Q.empty()) {
			auto now = Q.front(); Q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = now.first + dx[i];
				int ny = now.second + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]) continue;
				if (board[nx][ny] == sboard) {
					result += sboard;
					Q.push({ nx,ny });
				}
				visited[nx][ny] = 1;
			}
		}

		// ���� ����
		if (sdice > sboard) {
			dirNum = (dirNum + 1) % 4;
		}
		else if (sdice < sboard) {
			dirNum = (dirNum - 1 + 4) % 4;
		}
		else dirNum = dirNum;
//		cout << "=======================\n";
//		cout << "cur: " << cur.first << ", " << cur.second << "\n";
//		cout << "sdice: " << sdice << "\n";
//		cout << "sboard: " << sboard << "\n";
//		cout << "dirNum: " << dirNum << "\n";
	}

	

	cout << result;
}