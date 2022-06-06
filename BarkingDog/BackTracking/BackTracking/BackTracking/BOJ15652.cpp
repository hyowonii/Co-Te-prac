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

	// ������ ���� ���ں��� ���� ���ڴ� ������ �ȵ�
	// k==0�� ���� 1�� ����
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