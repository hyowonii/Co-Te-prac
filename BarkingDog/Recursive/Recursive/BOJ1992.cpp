#include <iostream>
using namespace std;

int n;
char board[65][65];
string result = "";

void recursion(int n, int a, int b) {
	char color = board[a][b];

	if (n == 1) {
		result += color;
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
		result += color;		
		return;
	}

	result += '(';
	recursion(n / 2, a, b);	
	recursion(n / 2, a, b + n / 2);
	recursion(n / 2, a + n / 2, b);
	recursion(n / 2, a + n / 2, b + n / 2);
	result += ')';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			board[i][j] = s[j];
		}
	}
	///////////////////입력

	recursion(n, 0, 0);
	cout << result;
}