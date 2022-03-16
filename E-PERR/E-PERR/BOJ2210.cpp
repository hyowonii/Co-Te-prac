#include <iostream>
#include <set>

using namespace std;

char board[5][5];
set<string> num_set;
string num = "000000";

void dfs(int x, int y, int cnt) {

	int dx[4] = { 0, -1, 0, 1 };
	int dy[4] = { -1, 0, 1, 0 };

	if (cnt == 6) {
		num_set.insert(num);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			num[cnt] = board[nx][ny];
			dfs(nx, ny, cnt + 1);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++) 
			cin >> board[i][j];
		
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0);
		}
	}

	cout << num_set.size();
}