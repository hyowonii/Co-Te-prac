#include <iostream>
using namespace std;
#include <queue>

#define X first
#define Y second
int N;
string pic[100];
string pic2[100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pic[i];
		pic2[i] = pic[i];
	}

	queue<pair<int, int>> Q;

	int num1 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c = pic[i][j];
			if (c == 'O') continue;
			Q.push({ i,j });
			pic[i][j] = 'O';

			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (pic[nx][ny] != c) continue;

					pic[nx][ny] = 'O';
					Q.push({ nx,ny });
				}
			}
			num1++;
		}
	}

	int num2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pic2[i][j] == 'G') pic2[i][j] = 'R';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c = pic2[i][j];
			if (c == 'O') continue;
			Q.push({ i,j });
			pic2[i][j] = 'O';

			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (pic2[nx][ny] != c) continue;

					pic2[nx][ny] = 'O';
					Q.push({ nx,ny });
				}
			}
			num2++;
		}
	}

	cout << num1 << " " << num2;

}