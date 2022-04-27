#include <iostream>
using namespace std;
#include <queue>

int N, M;
int A[51][51];	// 바구니 물
bool cloud[51][51] = { 0 };	// 구름 위치
queue<pair<int, int>> tmp;	// 구름 이동 temp
queue<pair<int, int>> DS;
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int da[] = { -1,1,1,-1 };
int db[] = { -1,-1,1,1 };

void move(int d, int s) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cloud[i][j] == 0) continue;

			int move = s % N;
			int x = i + dx[d - 1] * move;
			int y = j + dy[d - 1] * move;
			if (x < 0) x += N;
			if (x >= N) x -= N;
			if (y < 0) y += N;
			if (y >= N) y -= N;
			tmp.push({ x,y });
		}
	}

	// 구름 위치 초기화
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cloud[i][j] = 0;

	while (!tmp.empty()) {
		auto cur = tmp.front(); tmp.pop();
		cloud[cur.first][cur.second] = 1;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
		DS.push({ d,s });
	}
	// 입력

	cloud[N - 1][0] = 1;
	cloud[N - 1][1] = 1;
	cloud[N - 2][0] = 1;
	cloud[N - 2][1] = 1;

	while (!DS.empty()) {
		auto ds = DS.front(); DS.pop();
		int d = ds.first;	// 방향
		int s = ds.second;	// 속력

		move(d, s);	// 구름 움직이기

		// 구름이 있는 칸에 비 1씩 내림
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (cloud[i][j] == 0) continue;	// 구름 없음

				A[i][j] += 1;
			}
		}

		// 물복사버그
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (cloud[i][j] == 0) continue;

				int num = 0;	// 대각선 중에 물이 있는 위치 개수
				for (int k = 0; k < 4; k++) {
					int a = i + da[k];
					int b = j + db[k];

					if (a < 0 || a >= N || b < 0 || b >= N || A[a][b] == 0) continue;

					num++;
				}

				A[i][j] += num;
			}
		}
		
		// 이제 구름이 있었던 칸을 제외한 나머지 칸 중에서 물의 양이 2 이상인 칸에 구름이 생긴다. 구름이 생기면 물의 양이 2만큼 줄어든다.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (cloud[i][j] == 1) {
					cloud[i][j] = 0;
					continue;
				}
				if (A[i][j] < 2) continue;

				cloud[i][j] = 1;
				A[i][j] -= 2;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result += A[i][j];
		}
	}

	cout << result;
}