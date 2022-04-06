#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int space[20][20];
int check[20][20];	// ** 상어 출발지점부터 떨어져 있는 거리를 기록 **
int locx, locy;	// 상어 위치
int body = 2;	// 상어 크기
int eat = 0;	// 먹은 물고기 수
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
		// 상어의 위치가 바뀔 때마다 먹을 수 있는 물고기를 새로 구해야하므로 -1로 초기화
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				check[i][j] = -1;

		check[locx][locy] = 0;	// 상어 위치
		space[locx][locy] = 0;	// 9 그대로 놔두면 물고기의 크기를 9로 인식하기 때문에 0으로 바꿔줌
		
		queue<pair<int, int>> q;	// bfs queue
		q.push({ locx,locy });

		// 먹을 수 있는 물고기를 찾아 상어의 거리를 계산
		vector<pair<int, int>> fish;	// 먹을 수 있는 물고기 저장
		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;	// 범위를 벗어나면
				if (space[nx][ny] > body) continue;	// 물고기가 상어보다 더 크면 
				if (check[nx][ny] != -1) continue;	// 이미 검사한 곳
				if (space[nx][ny] == body || space[nx][ny] == 0) {	// 그냥 지나가는 경우
					check[nx][ny] = check[cur.first][cur.second] + 1;	// 상어가 지나온 거리가 계산됨
					q.push({ nx,ny });
				}
				if (0 < space[nx][ny] && space[nx][ny] < body) {
					check[nx][ny] = check[cur.first][cur.second] + 1;
					fish.push_back({ nx,ny });
					q.push({ nx,ny });
				}	
			}
		}
		// 상어의 출발 위치로부터 모든 배열 탐색, 먹을 수 있는 물고기 fish에 저장되고 최소거리 알 수 있음


		if (fish.size() == 0) {	// 먹을 수 있는 물고기가 없음
			cout << result;
			return 0;
		}
		if (fish.size() == 1) {
			result = check[fish.front().first][fish.front().second];
		}

	}
	

	cout << result;
	
}