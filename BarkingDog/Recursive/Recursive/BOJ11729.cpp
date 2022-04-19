#include <iostream>
using namespace std;

int result = 0;

void hanoi(int n, int from, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}

	hanoi(n - 1, from, 6 - from - to);
	cout << from << " " << to << "\n";	// °¡Àå ¹ØÀÇ Å« ¿øÆÇ ¿Å±è
	hanoi(n - 1, 6 - from - to, to);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";	// ÃÑ ÀÌµ¿È½¼ö: 2^n - 1
	hanoi(n, 1, 3);
}