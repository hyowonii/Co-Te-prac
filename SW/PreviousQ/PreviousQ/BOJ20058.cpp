#include <iostream>
using namespace std;
#include <vector>

int N, M, K;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
struct Fireball {
	int r, c, m, s, d;
};

vector<Fireball> before;	// 움직이기 전
vector<Fireball> after[51][51];

void move(Fireball ball) {
	int r = ball.r;
	int c = ball.c;
	int move = ball.s % N;	// **************
	r += dx[ball.d] * move;
	c += dy[ball.d] * move;
	if (r < 0) r += N;
	if (r >= N) r -= N;
	if (c < 0) c += N;
	if (c >= N) c -= N;

	after[r][c].push_back({ r, c, ball.m, ball.s, ball.d });
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		before.push_back({ r - 1, c - 1, m, s, d });
	}
	// 입력

	while (K--) {
		for (int i = 0; i < before.size(); i++) {
			auto ball = before[i];
			move(ball);
		}

		before.clear();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (after[i][j].size() == 0) continue;
				if (after[i][j].size() == 1) {
					before.push_back(after[i][j].front());
					after[i][j].clear();
					continue;
				}

				int m = 0, s = 0;
				int all = 0;
				for (int k = 0; k < after[i][j].size(); k++) {
					m += after[i][j][k].m;
					s += after[i][j][k].s;
					if (after[i][j][k].d % 2 == 0) all++;
				}

				m /= 5;
				s /= (after[i][j].size());
				int d = 1;
				if (all == 0 || all == after[i][j].size()) d = 0;
				if (m == 0) {
					after[i][j].clear();
					continue;
				}
				for (int k = 0; k < 4; k++)
					before.push_back({ i, j, m, s, d + k * 2 });

				after[i][j].clear();
			}
		}
	}

	int result = 0;
	for (int i = 0; i < before.size(); i++) {
		result += before[i].m;
	}

	cout << result;
}