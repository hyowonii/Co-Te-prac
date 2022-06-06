#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int space[20][20];
int check[20][20];	// ** ��� ����������� ������ �ִ� �Ÿ��� ��� **
int locx, locy;	// ��� ��ġ
int body = 2;	// ��� ũ��
int eat = 0;	// ���� ����� ��
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int result = 0;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				locx = i;
				locy = j;
			}
		}
	
	while (1) {
		// ����� ��ġ�� �ٲ� ������ ���� �� �ִ� ����⸦ ���� ���ؾ��ϹǷ� -1�� �ʱ�ȭ
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				check[i][j] = -1;

		check[locx][locy] = 0;	// ��� ��ġ
		space[locx][locy] = 0;	// 9 �״�� ���θ� ������� ũ�⸦ 9�� �ν��ϱ� ������ 0���� �ٲ���
		
		queue<pair<int, int>> q;	// bfs queue
		q.push({ locx,locy });

		// ���� �� �ִ� ����⸦ ã�� ����� �Ÿ��� ���
		vector<pair<int, int>> fish;	// ���� �� �ִ� ����� ����
		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;	// ������ �����
				if (space[nx][ny] > body) continue;	// ����Ⱑ ���� �� ũ�� 
				if (check[nx][ny] != -1) continue;	// �̹� �˻��� ��
				if (space[nx][ny] == body || space[nx][ny] == 0) {	// �׳� �������� ���
					check[nx][ny] = check[cur.first][cur.second] + 1;	// �� ������ �Ÿ��� ����
					q.push({ nx,ny });
				}
				if (0 < space[nx][ny] && space[nx][ny] < body) {
					check[nx][ny] = check[cur.first][cur.second] + 1;
					fish.push_back({ nx,ny });
					q.push({ nx,ny });
				}	
			}
		}
		// ����� ��� ��ġ�κ��� ��� �迭 Ž��, ���� �� �ִ� ����� fish�� ����ǰ� �ּҰŸ� �� �� ����


		if (fish.size() == 0) {	// ���� �� �ִ� ����Ⱑ ����
			cout << result;
			return 0;
		}
		if (fish.size() == 1) {
			result = check[fish.front().first][fish.front().second];
		}

	}
	

	cout << result;
	
}