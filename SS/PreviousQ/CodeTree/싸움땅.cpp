// priority_queue로 변형시키기

#include <iostream>
#include <set>
using namespace std;

int n;	// 격자 크기
int m;	// 플레이어 수
int k;	// 라운드 수
multiset<int> board[21][21];	// 격자판
int dx[4] = { -1,0,1,0 };	// 상 우 하 좌
int dy[4] = { 0,1,0,-1 };

struct Player {
	int x, y;	// (x,y) 위치
	int d;	// 방향
	int s;	// 플레이어 초기 능력치
	int point;	// 획득 포인트
	int gun = 0;	// 플레이어가 가진 총
}p[31];

// 입력
void init() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (a != 0) board[i][j].insert(a);
		}
	}
	for (int i = 1; i <= m; i++) {	// 플레이어 초기화
		cin >> p[i].x >> p[i].y >> p[i].d >> p[i].s;
	}
}

// 1. i번 플레이어 이동
void movePlayer(int idx) {
	// i번 플레이어 정보
	int X = p[idx].x;
	int Y = p[idx].y;
	int D = p[idx].d;

	int nx = X + dx[D];
	int ny = Y + dy[D];
	if (nx <= 0 || nx > n || ny <= 0 || ny > n) {
		D = (D + 2) % 4;	// 방향 반대로 바꿈
		nx = X + dx[D];
		ny = Y + dy[D];
		p[idx].d = D;
	}

	p[idx].x = nx;
	p[idx].y = ny;
}

// 이동한 칸에 플레이어가 있는지 총이 있는지 확인하는 함수
int checkBoardCell(int idx, int locX, int locY) {
	for (int i = 1; i <= m; i++) {
		if (i == idx) continue;
		if (p[i].x == locX && p[i].y == locY) return i;
	}
	return 0;
}

// 3. 총 있으면 줍기
void getGun(int idx) {
	int X = p[idx].x;
	int Y = p[idx].y;

	if (!board[X][Y].empty()) {	// 빈 칸이 아닌 총이 있으면
		auto it = board[X][Y].rbegin();
		int newGun = *it;	// 가장 큰 총
		if (p[idx].gun < newGun) {	// 총을 안가지고 있거나 새 총이 더 크면
			int tmp = p[idx].gun;
			p[idx].gun = newGun;	// 새 총을 가짐
			board[X][Y].erase(board[X][Y].find(newGun));	// 가진 총 격자에서 없앰
			if (tmp != 0) board[X][Y].insert(tmp);	// 원래 가지고 있던 총 격자에 놓음
		}
		// 내가 가진 총이 더 크면 아무것도 안함
	}
}

// 2. 플레이어 있으면 싸우기 - 진 플레이어 리턴
pair<int,int> fight(int idx1, int idx2) {
	Player p1 = p[idx1];
	Player p2 = p[idx2];

	int power1 = p1.s + p1.gun;
	int power2 = p2.s + p2.gun;
	int getPoint = abs(power1 - power2);
	if (power1 > power2) {
		p[idx1].point = getPoint;
		return make_pair(idx1, idx2);
	}
	else if (power1 < power2) {
		p[idx2].point = getPoint;
		return make_pair(idx2, idx1);
	}
	else {
		if (p1.s > p2.s) {
			p[idx1].point = getPoint;
			return make_pair(idx1, idx2);
		}
		else {
			p[idx2].point = getPoint;
			return make_pair(idx2, idx1);
		}
	}
}

// 2-1. 진 플레이어 이동
void moveAfterFight(int idx) {
	int X = p[idx].x;
	int Y = p[idx].y;	// 싸운 위치
	int dir = p[idx].d;
	if (p[idx].gun != 0) {
		board[X][Y].insert(p[idx].gun);	// 총 격자에 내려놓음
		p[idx].gun = 0;	// 총 없음
	}
	int nx = X + dx[dir];
	int ny = Y + dy[dir];
	if (nx <= 0 || nx > n || ny <= 0 || ny > n || checkBoardCell(idx, nx, ny) != -1) {
		dir = (dir + 1) % 4;	// 오른쪽 90도 회전
		nx = X + dx[dir];
		ny = Y + dy[dir];
	}
	p[idx].x = nx;
	p[idx].y = ny;
	p[idx].d = dir;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력
	init();

	///테스트
		//movePlayer(1);
		//cout << p[1].x << " " << p[1].y << "\n";
		//int player = checkBoardCell(1, p[1].x, p[1].y);
		//cout << "player: " << player << "\n";
		//if (player != -1) {
		//	int lose = fight(1, player);	// 진 플레이어 인덱스 리턴

		//	// 2-1. 진 플레이어 이동
		//	moveAfterFight(lose);
		//}
		//getGune(1);
		//cout << p[1].gun << "\n";

		//movePlayer(2);
		//cout << p[2].x << " " << p[2].y << "\n";
		//int player1 = checkBoardCell(2, p[2].x, p[2].y);
		//cout << "player1: " << player1 << "\n";
		//if (player1 != -1) {
		//	int lose = fight(2, player1);	// 진 플레이어 인덱스 리턴
		//	cout << "loser: " << lose << "\n";
		//	// 2-1. 진 플레이어 이동
		//	moveAfterFight(lose);
		//	cout << "loser: " << p[lose].x << " " << p[lose].y << "\n";
		//}
		//getGune(2);
		//cout << p[2].gun << "\n";

		//cout << "point: " << p[1].point << " " << p[2].point << "\n";
	////


	while (k--) {

		for (int idx = 1; idx <= m; idx++) {	// 1~m 플레이어 이동

			// 1. i번 플레이어 이동
			movePlayer(idx);

			// 이동한 칸에 플레이어가 있는지 총이 있는지 확인하는 함수
			int player = checkBoardCell(idx, p[idx].x, p[idx].y);	// 칸에 있는 플레이어 인덱스 번호 리턴, 없으면 -1

			// 2. if 플레이어 있으면 싸우기 
			if (player != 0) {
				pair<int,int> wl = fight(idx, player);	// 진 플레이어 인덱스 리턴

				// 2-1. 진 플레이어 이동
				moveAfterFight(wl.second);
				getGun(wl.second);
				getGun(wl.first);
			}

			// 3. else 총 있으면 줍기
			else getGun(idx);

		}
	}

	int result[31] = { 0 };
	for (int i = 1; i <= m; i++) result[i] = p[i].point;
	for (int i = 1; i <= m; i++) cout << result[i] << " ";

}