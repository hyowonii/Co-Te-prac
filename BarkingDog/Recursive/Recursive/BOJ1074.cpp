#include <iostream>

using namespace std;



int recursion(int n, int r, int c) {
	// basic condition
	if (n == 0) return 0;

	int half = 1 << (n - 1);
	if (r < half && c < half) return recursion(n - 1, r, c);	// 1�� �簢��
	if (r < half && c >= half) return half * half + recursion(n - 1, r, c - half);	// 2�� �簢��
	if (r >= half && c < half) return 2 * half * half + recursion(n - 1, r - half, c);	// 3�� �ﰢ��
	return 3 * half * half + recursion(n - 1, r - half, c - half);	// 4�� �簢��
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, r, c;
	cin >> N >> r >> c;

	cout << recursion(N, r, c);
}