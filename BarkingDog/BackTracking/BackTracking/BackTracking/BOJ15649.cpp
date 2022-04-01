#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool isused[10];

void func(int k) {	// ���� k������ ���� ������

	if (k == M) {	// M���� ��� ��������
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {	
		if (!isused[i]) {	// ���� i�� ������ �ʾ�����
			arr[k] = i;	// k��° ���� i�� 
			isused[i] = 1;	// i�� ���Ǿ��ٰ� ǥ��
			func(k + 1);
			isused[i] = 0;	// k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ�������Ƿ� ���� i�� ������ �ʾҴٰ� ���
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	func(0);
}