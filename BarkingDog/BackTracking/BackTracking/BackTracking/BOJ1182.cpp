#include <iostream>
using namespace std;

int n, s;
int arr[20];
int result = 0;

void func(int cur, int total) {
	if (cur == n) {
		if (total == s) result++;
		return;
	}

	func(cur + 1, total);
	func(cur + 1, total + arr[cur]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	func(0, 0);
	if (s == 0) result--;	// 공집합일 때
	cout << result;
}