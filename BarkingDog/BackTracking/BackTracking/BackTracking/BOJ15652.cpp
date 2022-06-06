#include <iostream>
using namespace std;
#include <algorithm>

int n, m;
int arr[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	// 직전에 넣은 숫자보다 작은 숫자는 나오면 안됨
	// k==0일 때는 1을 넣음
	for (int i = (k == 0) ? 1 : arr[k-1]; i <= n; i++) {
		arr[k] = i;
		func(k + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	func(0);
}