#include <iostream>
using namespace std;
#include <algorithm>

int n, m;
int num[10];
int arr[10];
bool isused[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	// 직전에 넣은 숫자보다 작은 숫자는 나오면 안됨
	for (int i = 0; i < n; i++) {
		if (!isused[i] && arr[k - 1] < num[i]) {
			arr[k] = num[i];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
		
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);

	func(0);
}