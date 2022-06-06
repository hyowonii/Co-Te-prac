#include <iostream>
using namespace std;

int n;
int board[130][130];
int white = 0, blue = 0;

void count(int num) {
	if (num == 0) white++;
	else blue++;
}

void recursion(int n, int a, int b) {
	int color = board[a][b];

	if (n == 1) {
		count(color);
		return;
	}

	bool tf = true;		// 모두 같은 색인지 판별
	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + n; j++) {
			if (board[i][j] == color) continue;
			else {
				tf = false;
				break;
			}
		}
	}

	if (tf) {	// 모두 같은 색이면
		count(color);
		return;
	}

	recursion(n / 2, a, b);
	recursion(n / 2, a + n / 2, b);
	recursion(n / 2, a, b + n / 2);
	recursion(n / 2, a + n / 2, b + n / 2);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	//////////////입력	
	
	recursion(n, 0, 0);
	cout << white << "\n" << blue;
}