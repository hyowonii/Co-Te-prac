#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define R first
#define C second

int n;	// 격자 변길이
int m;	// 횟수
int board[51][51];	// 격자
vector<pair<int, int>> mvds;	// 구름 이동
int dr[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dc[9] = { 0,-1,-1,0,1,1,1,0,-1 };
vector<pair<int, int>> cloud;	// 비구름 좌표

// 입력
void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	for (int i = 0; i < m; i++) {
		int d, s;
		cin >> d >> s;
		mvds.push_back(make_pair(d, s));
	}
}

// 1. (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름
void initCloud() {
	cloud.push_back(make_pair(n, 1));
	cloud.push_back(make_pair(n, 2));
	cloud.push_back(make_pair(n-1, 1));
	cloud.push_back(make_pair(n-1, 2));
}

// 2. 구름 이동
void moveCloud() {
	pair<int, int> ds = mvds.front();
	mvds.erase(mvds.begin(), mvds.begin() + 1);
	int d = ds.first;
	int s = ds.second;
	int size = cloud.size();
	for (int i = 0; i < size; i++) {
		auto cur = cloud[i];	// 이동 전 구름
		int nxtR = (cur.R + (dr[d] * s) + 50 * n) % n;
		int nxtC = (cur.C + (dc[d] * s) + 50 * n) % n;
		if (nxtR == 0) nxtR = n;
		if (nxtC == 0) nxtC = n;
		//cout << "cur: (" << cur.R << ", " << cur.C << ") -> nxt: (" << nxtR << ", " << nxtC << ")\n";
		cloud.push_back({ nxtR, nxtC });	// 이동한 구름 위치 삽입
	}
	cloud.erase(cloud.begin(), cloud.begin() + size);	// 이전 구름 위치 삭제
}

// 3. 비 내림
void rains() {
	for (int i = 0; i < cloud.size(); i++) {
		auto cur = cloud[i];
		board[cur.R][cur.C]++;
	}
}

// 5. 물복사버그 (물이 증가한 칸 == 비구름 있던 칸)
void waterBug() {
	int ddr[4] = { 1,1,-1,-1 };
	int ddc[4] = { -1,1,-1,1 };
	for (int i = 0; i < cloud.size(); i++) {
		auto cur = cloud[i];	// 물이 증가한 칸
		int r = cur.R;
		int c = cur.C;
		int sum = 0;	// (r,c)에 증가시킬 총 물의 양 - 물이 있는 바구니 수 합
		for (int k = 0; k < 4; k++) {
			int nr = r + ddr[k];
			int nc = c + ddc[k];
			if (nr <= 0 || nr > n || nc <= 0 || nc > n) continue;
			if (board[nr][nc] != 0) sum++;
		}
		board[cur.R][cur.C] += sum;
	}
}

// 6. 구름 생김 + 비구름 없애기
void makeCloud() {
	int size = cloud.size();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (find(cloud.begin(), cloud.end(), make_pair(i, j)) != cloud.end()) continue;
			if (board[i][j] >= 2) {
				cloud.push_back({ i,j });	// 비구름 생성
				board[i][j] -= 2;	// 물 양 -2
			}
		}
	}
	cloud.erase(cloud.begin(), cloud.begin() + size);	// 이전에 비구름 있던 칸 지움
}


void print() {
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

	// 입력
	init();

	// 1. (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름
	initCloud();

	//moveCloud();
	//rains();
	//waterBug();
	//makeCloud();
	//print();


	while (m--) {
		// 2. 구름 이동
		moveCloud();

		// 3. 비 내림
		rains();

		// 4. 구름 사라짐 (6번에서 처리)

		// 5. 물복사버그 (물이 증가한 칸 == 비구름 있던 칸)
		waterBug();

		// 6. 구름 생김
		makeCloud();

	}

	// 모든 바구니에 든 물 양의 합
	int result = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			result += board[i][j];

	cout << result;

}