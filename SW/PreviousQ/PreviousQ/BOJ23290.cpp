/*
삼성 코딩테스트 기출문제
마법사 상어와 복제
*/

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
typedef pair<int, int> pi;

int M, S;
vector<int> before[4][4];	// 이동 전 물고기의 위치
vector<int> after[4][4];	// 이동 후 물고기의 위치
pi shark;
vector<int> shark_road;
int dirX[8] = { 0,-1,-1,-1,0,1,1,1 };
int dirY[8] = { -1,-1,0,1,1,1,0,-1 };
int smell[4][4] = { 0 };	// 물고기 냄새
int dirSharkX[4] = { -1,0,1,0 };
int dirSharkY[4] = { 0,-1,0,1 };

void move_fish(int time) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < before[i][j].size(); k++) {
				int move = before[i][j][k];
				int pmove;
				bool flag = false;
				for (int rotate = 0; rotate < 8; rotate++) {
					pmove = (move - rotate + 8) % 8;
					int nx = i + dirX[pmove];
					int ny = j + dirY[pmove];
					if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
					if (nx == shark.first && ny == shark.second) continue;
					if (smell[nx][ny] != 0 && time - smell[nx][ny] <= 2) continue;
					
					after[nx][ny].push_back(pmove);
					flag = true;
					break;
					
				}

				// 움직일 수 없으면
				if (flag == false) after[i][j].push_back(move);
			}
		}
	}
}

void check_shark(vector<int> route, int mx) {
	if (route.size() == 3) {
		// 3번 이동한 후
		int x = shark.first;
		int y = shark.second;
		bool visited[4][4] = { false };
		int cnt = 0;
		for (auto move : route) {
			x += dirSharkX[move];
			y += dirSharkY[move];
			if (x < 0 || x >= 4 || y < 0 || y >= 4) return;
			if (!visited[x][y]) {
				visited[x][y] = true;
				cnt += after[x][y].size();
			}
		}
		if (cnt > mx) {
			shark_road = route;
			mx = cnt;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		route.push_back(i);
		check_shark(route, mx);
		route.pop_back();
	}
}

void move_shark() {
	for (auto sh : shark_road) {
		shark.first += dirSharkX[sh];
		shark.second += dirSharkY[sh];
		if (after[shark.first][shark.second].size() != 0) {	// 상어가 물고기 만나면
			after[shark.first][shark.second].clear();
			smell[shark.first][shark.second]++;
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> S;
	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		before[x-1][y-1].push_back(d - 1);
	}
	int sx, sy;
	cin >> sx >> sy;
	shark.first = sx - 1;
	shark.second = sy - 1;
	// 입력


	for (int s = 0; s < S; s++) {

		// 물고기 이동
		move_fish(s);

		// 상어 이동
		vector<int> tmp;
		check_shark(tmp, -1);
		move_shark();

		// 물고기 복제
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (auto fish : after[i][j]) {
					before[i][j].push_back(fish);
				}
				after[i][j].clear();
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result += before[i][j].size();
		}
	}
	cout << result;
}

