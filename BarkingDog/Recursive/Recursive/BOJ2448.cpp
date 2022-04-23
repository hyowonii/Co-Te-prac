#include <iostream>
using namespace std;

const int MAX = 1024 * 3 + 2;

int n;
char board[MAX][MAX * 2 - 1];

void recursion(int n, int a, int b) {
	if (n == 3) {
		board[a][b] = '*';
		board[a + 1][b - 1] = '*'; board[a + 1][b + 1] = '*';
		for (int i = b - 2; i <= b + 2; i++) {
			board[a + 2][i] = '*';
		}
		return;
	}

	recursion(n / 2, a, b);
	recursion(n / 2, a + n / 2, b - n / 2);
	recursion(n / 2, a + n / 2, b + n / 2);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + 2 * n - 1, ' ');		// 2 * n - 1

	recursion(n, 0, n - 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
}