#include <iostream>
using namespace std;

int n;
int result = 0;

bool isused1[40];	// ������
bool isused2[40];	// �밢��1 (x, y)���� �ε����� x+y
bool isused3[40];	// �밢��2 (x, y)���� �ε����� x-y+n-1

void func(int cur) {
	if (cur == n) {
		result++;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1]) continue;
		isused1[i] = 1;
		isused2[cur + i] = 1;
		isused3[cur - i + n - 1] = 1;

		func(cur + 1);
		isused1[i] = 0;
		isused2[cur + i] = 0;
		isused3[cur - i + n - 1] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	func(0);
	cout << result;
}