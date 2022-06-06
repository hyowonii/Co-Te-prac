#include <iostream>
using namespace std;

int n;
char board[2300][2300];

void recursion(int n, int a, int b) {
	if (n == 3) {
		board[a][b] = '*'; board[a][b + 1] = '*'; board[a][b + 2] = '*';
		board[a + 1][b] = '*'; board[a + 1][b + 1] = ' '; board[a + 1][b + 2] = '*';
		board[a + 2][b] = '*'; board[a + 2][b + 1] = '*'; board[a + 2][b + 2] = '*';
		return;
	}

	recursion(n / 3, a, b); recursion(n / 3, a, b + n / 3); recursion(n / 3, a, b + 2 * n / 3);
	recursion(n / 3, a + n / 3, b); recursion(n / 3, a + n / 3, b + 2 * n / 3);
	recursion(n / 3, a + 2 * n / 3, b); recursion(n / 3, a + 2 * n / 3, b + n / 3); recursion(n / 3, a + 2 * n / 3, b + 2 * n / 3);


	/////////////////////////////
	//다른풀이
/*
	if (n == 1) {
		board[a][b] = '*';
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			recursion(n / 3, a + n / 3 * i, b + n / 3 * j);
		}
	}
*/
	////////////////////////////
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + n, ' ');	// 모두 빈 문자로 초기화

	recursion(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
}