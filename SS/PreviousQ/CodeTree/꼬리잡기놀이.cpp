#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;

int n;	// 격자 크기
int m;	// 팀 개수
int k;	// 라운드 수
int board[21][21];
vector<pair<int, int>> teams[6];	// 사람들 위치
int score[6] = { 0 };	// 팀별 획득 점수
int dx[4] = { 0,1,0,-1 };	// 우 하 좌 상
int dy[4] = { 1,0,-1,0 };


// 입력
void input() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
}

// 보드판 범위 넘어가는지 체크
bool overRange(int a, int b) {
	if (a <= 0 || a > n || b <= 0 || b > n) return true;
	return false;
}

// 팀 저장
void SaveTeams() {	// DFS
	int teamIdx = 0;	// 팀 인덱스
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] != 1) continue;
			// 머리사람에서 시작
			teams[teamIdx].push_back({ i,j });
			stack<pair<int, int>> S;
			bool vis[21][21] = { 0 };
			S.push({ i,j });
			vis[i][j] = true;
			pair<int, int> cur;
			while (!S.empty()) {
				cur = S.top();	S.pop();
				for (int k = 0; k < 4; k++) {
					int nx = cur.first + dx[k];
					int ny = cur.second + dy[k];
					if (overRange(nx,ny)) continue;
					if (vis[nx][ny]) continue;
					if (board[nx][ny] == 2) {
						teams[teamIdx].push_back({ nx,ny });
						S.push({ nx,ny });
						vis[nx][ny] = true;
						break;
					}
				}
			}
			for (int k = 0; k < 4; k++) {
				int nx = cur.first + dx[k];
				int ny = cur.second + dy[k];
				if (overRange(nx, ny)) continue;
				if (vis[nx][ny]) continue;
				if (board[nx][ny] == 3) {
					teams[teamIdx].push_back({ nx,ny });
					break;
				}
			}
			teamIdx++;
		}
	}
}

// 1. 모든 팀 머리사람 따라 1칸 이동
void Move(int idx) {
	vector<pair<int, int>> team = teams[idx];
	int nxtHeadx, nxtHeady;	// 1이 이동할 위치 따로 저장해두었다가 마지막에 이동
	int nx = team[0].first;
	int ny = team[0].second;
	for (int i = 0; i < 4; i++) {	// 1이 이동할 위치 찾기
		nxtHeadx = team[0].first + dx[i];
		nxtHeady = team[0].second + dy[i];
		if (overRange(nxtHeadx, nxtHeady)) continue;
		if (board[nxtHeadx][nxtHeady] == 4) break;
		if (board[nxtHeadx][nxtHeady] == 3) break;	// 4가 없이 3이 있으면: 머리와 꼬리가 연결된 것
	}

	for (int i = 1; i < team.size(); i++) {
		auto cur = team[i];
		board[nx][ny] = board[cur.first][cur.second];
		team[i] = { nx,ny };
		nx = cur.first;
		ny = cur.second;
	}
	board[nx][ny] = 4;	// 3이 이동했던 자리 4로 바꿈
	board[nxtHeadx][nxtHeady] = 1;	// 1번 이동
	team[0] = { nxtHeadx,nxtHeady };

	teams[idx] = team;	// 팀에도 넣어줘야 함
}

// 공이 던져지는 라인 구하기
tuple<int, int, int> ball(int round) {
	tuple<int, int, int> result;
	round %= (4 * n);
	if (round == 0) round = 4 * n;

	if (round >= 1 && round <= n) {
		result = make_tuple(round, 1, 0);
	}
	else if (round >= n + 1 && round <= 2 * n) {
		result = make_tuple(n, round - n, 3);
	}
	else if (round >= 2 * n + 1 && round <= 3 * n) {
		result = make_tuple(3 * n - round + 1, n, 2);
	}
	else {
		result = make_tuple(1, 4 * n - round + 1, 1);
	}

	return result;
}

// 2. 공 던져짐, 3. 공 받아서 점수 얻음
void throwBall(int round) {
	tuple<int, int, int> line = ball(round);	// 시작 행,열과 방향
	int row = get<0>(line);	// 시작 행
	int col = get<1>(line);	// 시작 열
	int dir = get<2>(line);	// 방향 0:우 1:하 2:좌 3:상
	
	int mx = row, my = col;
	while (1) {
		if (overRange(mx, my)) break;
		if (board[mx][my] >= 1 && board[mx][my] <= 3) {	// 사람 만남
			break;
		}
		mx += dx[dir];
		my += dy[dir];
	}

	if (!overRange(mx, my)) {	// 만난사람 있으면
		int getScore = 0;	// 얻을 점수
		for (int i = 0; i < m; i++) {
			auto team = teams[i];
			auto it = find(team.begin(), team.end(), make_pair(mx, my));
			if (it != team.end()) {
				// 점수 획득
				getScore = pow(it - team.begin() + 1, 2);
				score[i] += getScore;

				// 방향 변경
				vector<pair<int, int>> tmp;
				for (int j = team.size() - 1; j >= 0; j--) {
					tmp.push_back(team[j]);
				}
				teams[i] = tmp;
				auto head = teams[i][0];
				auto tail = teams[i][teams[i].size() - 1];
				board[head.first][head.second] = 1;
				board[tail.first][tail.second] = 3;

				break;
			}
		}
	}
}

// 프린트
void print() {
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	// ***************** 테스트 ************************
	//input();
	//cout << "\nSaveTeams\n";
	//SaveTeams();
	//for (int i = 0; i < m; i++) {
	//	auto team = teams[i];
	//	cout << "\nteam " << i << "\n";
	//	for (int j = 0; j < team.size(); j++) {
	//		cout << team[j].first << ", " << team[j].second << "\n";
	//	}
	//}
	//cout << "\nMpve\n";
	//for (int idx = 0; idx < m; idx++) {
	//	Move(idx);
	//}
	//print();
	//throwBall(1);

	// *************************************************

	// 입력
	input();

	// 팀 저장
	SaveTeams();

	for(int round = 1; round <= k; round++) {
		
		// 1. 모든 팀 머리사람 따라 1칸 이동
		for (int idx = 0; idx < m; idx++) {
			Move(idx);
		}

		// 2. 공 던져짐, 3. 공 받아서 점수 얻음
		throwBall(round);
		
	}

	int total = 0;
	for (int i = 0; i < m; i++) total += score[i];
	cout << total;
}